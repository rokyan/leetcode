// https://leetcode.com/problems/number-of-islands-ii/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(std::size_t n)
        {
            size.resize(n);
            parent.resize(n);

            for (auto v = 0; v < n; v++)
            {
                size[v] = 1;
                parent[v] = v;
            }
        }

        int find(int v)
        {
            if (parent[v] == v)
            {
                return v;
            }

            return (parent[v] = find(parent[v]));
        }

        bool merge(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return false;
            }

            if (size[u] > size[v])
            {
                parent[v] = u;
                size[u] += size[v];
            }
            else
            {
                parent[u] = v;
                size[v] += size[u];
            }

            return true;
        }
    
    private:
        std::vector<int> size;
        std::vector<int> parent;
    };

public:
    std::vector<int> numIslands2(int m, int n, const std::vector<std::vector<int>>& positions)
    {
        Dsu dsu(m * n);

        std::vector<int> res;
        res.reserve(std::size(positions));

        std::array<int, 4> dr{1, 0, -1, 0};
        std::array<int, 4> dc{0, -1, 0, 1};

        auto cnt = 0;

        std::unordered_set<int> marked;

        for (const auto& pos : positions)
        {
            if (marked.count(pos[0] * n + pos[1]) == 0)
            {
                cnt++;
            }
            else
            {
                res.push_back(cnt);
                continue;
            }

            std::unordered_set<int> neigh;

            for (auto idx = 0; idx < 4; idx++)
            {
                const auto r = pos[0] + dr[idx];
                const auto c = pos[1] + dc[idx];

                if (r >= 0 && r < m && c >= 0 && c < n && marked.count(r * n + c) > 0)
                {
                    neigh.insert(dsu.find(r * n + c));
                }
            }

            for (auto idx = 0; idx < 4; idx++)
            {
                const auto r = pos[0] + dr[idx];
                const auto c = pos[1] + dc[idx];

                if (r >= 0 && r < m && c >= 0 && c < n && marked.count(r * n + c) > 0)
                {
                    dsu.merge(pos[0] * n + pos[1], r * n + c);
                }
            }

            cnt -= std::size(neigh);

            marked.insert(pos[0] * n + pos[1]);

            res.push_back(cnt);
        }

        return res;
    }
};