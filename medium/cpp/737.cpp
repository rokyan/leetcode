// https://leetcode.com/problems/sentence-similarity-ii/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(int n)
        {
            init(n);
        }

        int find(int v)
        {
            if (v == parent[v])
            {
                return v;
            }

            return (parent[v] = find(parent[v]));
        }

        void un(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u != v)
            {
                if (size[u] > size[v])
                {
                    std::swap(u, v);
                }

                parent[u] = v;
                size[v] += size[u];
            }
        }

        bool same(int u, int v)
        {
            return find(u) == find(v);
        }

    private:
        void init(int n)
        {
            parent.resize(n);
            std::iota(std::begin(parent), std::end(parent), 0);

            size.resize(n, 1);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };
public:
    bool areSentencesSimilarTwo(std::vector<std::string>& sentence1, std::vector<std::string>& sentence2, std::vector<std::vector<std::string>>& similarPairs)
    {
        const auto n = std::size(sentence1);

        if (std::size(sentence2) != n)
        {
            return false;
        }

        std::map<std::string, int> compressed;

        for (const auto& p : similarPairs)
        {
            if (compressed.find(p[0]) == std::end(compressed))
            {
                compressed.emplace(p[0], std::size(compressed));
            }

            if (compressed.find(p[1]) == std::end(compressed))
            {
                compressed.emplace(p[1], std::size(compressed));
            }
        }

        auto dsu = Dsu{ static_cast<int>(std::size(compressed)) };

        for (const auto& p : similarPairs)
        {
            dsu.un(compressed[p[0]], compressed[p[1]]);
        }

        for (auto i = 0; i < n; i++)
        {
            const auto& s1 = sentence1[i];
            const auto& s2 = sentence2[i];

            auto same = s1 == s2;

            if (!same)
            {
                auto id1 = -1;

                if (const auto it = compressed.find(s1); it != std::end(compressed))
                {
                    id1 = it->second;
                }

                auto id2 = -1;

                if (const auto it = compressed.find(s2); it != std::end(compressed))
                {
                    id2 = it->second;
                }

                same = id1 != -1 && id2 != -1 && dsu.same(id1, id2);
            }

            if (!same)
            {
                return false;
            }
        }

        return true;
    }
};