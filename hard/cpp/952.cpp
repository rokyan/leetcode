// https://leetcode.com/problems/largest-component-size-by-common-factor/description/

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

        int max() const
        {
            return *std::max_element(std::cbegin(size), std::cend(size));
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
    int largestComponentSize(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        auto dsu = Dsu{ n };

        std::unordered_map<int, int> idx;

        for (auto i = 0; i < n; i++)
        {
            auto num = nums[i];

            for (auto div = 2; div * div <= num; div++)
            {
                if (num % div == 0)
                {
                    if (const auto it = idx.find(div); it != std::end(idx))
                    {
                        dsu.merge(it->second, i);
                    }
                    else
                    {
                        idx.emplace(div, i);
                    }

                    while (num % div == 0)
                    {
                        num /= div;
                    }
                }
            }

            if (num > 1)
            {
                if (const auto it = idx.find(num); it != std::end(idx))
                {
                    dsu.merge(it->second, i);
                }
                else
                {
                    idx.emplace(num, i);
                }
            }
        }

        return dsu.max();
    }
};