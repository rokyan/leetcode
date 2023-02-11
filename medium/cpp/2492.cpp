// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

class Solution
{
public:
    int minScore(int n, std::vector<std::vector<int>>& roads)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& road : roads)
        {
            const auto u = road[0] - 1;
            const auto v = road[1] - 1;
            const auto d = road[2];

            graph[u].emplace_back(v, d);
            graph[v].emplace_back(u, d);
        }

        std::vector<char> visited(n);

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                auto res = -1;

                dfs(v, n, res, graph, visited);

                if (visited[0] && visited[n - 1])
                {
                    return res;
                }
            }
        }

        return -1;
    }

private:
    void dfs(int v, int n, int& res, const std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<char>& visited)
    {
        visited[v] = true;

        for (const auto& e : graph[v])
        {
            const auto to = e.first;
            const auto dist = e.second;

            res = (res == -1) ? dist : std::min(res, dist);

            if (visited[to])
            {
                continue;
            }

            dfs(to, n, res, graph, visited);
        }
    }
};