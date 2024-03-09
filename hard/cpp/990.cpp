// https://leetcode.com/problems/satisfiability-of-equality-equations/description/

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

        bool same(int u, int v)
        {
            return find(u) == find(v);
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
    bool equationsPossible(std::vector<std::string>& equations)
    {
        std::unordered_map<char, int> mapping;

        for (const auto& eq : equations)
        {
            mapping[eq[0]] = mapping[eq[3]] = 0;
        }

        auto id = 0;

        for (auto& e : mapping)
        {
            e.second = id++;
        }

        auto dsu = Dsu{ static_cast<int>(std::size(mapping)) };

        for (const auto& eq : equations)
        {
            if (eq[1] == eq[2])
            {
                dsu.merge(mapping[eq[0]], mapping[eq[3]]);
            }
        }

        for (const auto& eq : equations)
        {
            if (eq[1] != eq[2])
            {
                if (dsu.same(mapping[eq[0]], mapping[eq[3]]))
                {
                    return false;
                }
            }
        }

        return true;
    }
};