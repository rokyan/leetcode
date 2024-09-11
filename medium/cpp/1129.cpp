// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

class Solution
{
public:
    std::vector<int> shortestAlternatingPaths(int n, const std::vector<std::vector<int>>& redEdges,
        const std::vector<std::vector<int>>& blueEdges)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : redEdges)
        {
            graph[edge[0]].push_back({ 0, edge[1] });
        }

        for (const auto& edge : blueEdges)
        {
            graph[edge[0]].push_back({ 1, edge[1] });
        }

        std::vector<std::vector<int>> dist(2, std::vector<int>(n, 2 * n + 1));
        dist[0][0] = dist[1][0] = 0;

        std::queue<std::pair<int, int>> q;
        q.push({ 0, 0 });
        q.push({ 1, 0 });

        while (!q.empty())
        {
            const auto [c, v] = q.front();
            q.pop();

            for (auto [cc, to] : graph[v])
            {
                if (cc != c && dist[cc][to] > dist[c][v] + 1)
                {
                    dist[cc][to] = dist[c][v] + 1;
                    q.push({ cc, to });
                }
            }
        }

        std::vector<int> res(n);

        for (auto i = 0; i < n; i++)
        {
            const auto d = std::min(dist[0][i], dist[1][i]);
            res[i] = d == 2 * n + 1 ? -1 : d;
        }

        return res;
    }
};