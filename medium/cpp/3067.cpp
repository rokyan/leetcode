// https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/

class Solution
{
public:
    std::vector<int> countPairsOfConnectableServers(std::vector<std::vector<int>>& edges, int signalSpeed)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        std::vector<int> res(n);

        for (auto v = 0; v < n; v++)
        {
            if (std::size(graph[v]) > 1)
            {
                std::vector<int> cnts;
                auto sum = 0;

                for (auto [to, w] : graph[v])
                {
                    cnts.push_back(dfs(to, v, w, signalSpeed, graph));
                    sum += cnts.back();
                }

                for (auto cnt : cnts)
                {
                    res[v] += cnt * (sum - cnt);
                }

                res[v] /= 2;
            }
        }

        return res;
    }

private:
    int dfs(int v, int p, int d, int m, const std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        auto cnt = 0;

        if (d % m == 0)
        {
            cnt++;
        }

        for (auto [to, w] : graph[v])
        {
            if (to != p)
            {
                cnt += dfs(to, v, d + w, m, graph);
            }
        }

        return cnt;
    }
};