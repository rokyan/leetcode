// https://leetcode.com/problems/similar-string-groups/description/

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

        void merge(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return;
            }

            if (size[u] > size[v])
            {
                std::swap(u, v);
            }

            parent[u] = v;
            size[v] += size[u];
        }

        int get_groups_count()
        {
            std::unordered_set<int> un;

            for (auto v = 0; v < std::size(parent); v++)
            {
                un.insert(find(v));
            }

            return static_cast<int>(std::size(un));
        }

    private:
        void init(int n)
        {
            parent.resize(n);
            std::iota(std::begin(parent), std::end(parent), 0);

            size.resize(n);
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    int numSimilarGroups(std::vector<std::string>& strs)
    {
        const auto n = static_cast<int>(std::size(strs));

        auto dsu = Dsu{ n };

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                if (similar(strs[i], strs[j]))
                {
                    dsu.merge(i, j);
                }
            }
        }

        return dsu.get_groups_count();
    }

private:
    static bool similar(const std::string& left, const std::string& right)
    {
        auto diff = 0;

        for (auto i = 0; i < std::size(left) && diff <= 2; i++)
        {
            diff += left[i] != right[i];
        }

        return diff <= 2;
    }
};