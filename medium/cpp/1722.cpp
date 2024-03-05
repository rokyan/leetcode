// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/

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
    int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target, std::vector<std::vector<int>>& allowedSwaps)
    {
        const auto n = static_cast<int>(std::size(source));

        Dsu dsu{ n };

        for (const auto& swap : allowedSwaps)
        {
            dsu.un(swap[0], swap[1]);
        }

        std::unordered_map<int, std::unordered_multiset<int>> groups;

        for (auto i = 0; i < n; i++)
        {
            groups[dsu.find(i)].insert(source[i]);
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            auto& group = groups[dsu.find(i)];

            if (const auto it = group.find(target[i]); it != std::end(group))
            {
                group.erase(it);
            }
            else
            {
                res++;
            }
        }

        return res;
    }
};