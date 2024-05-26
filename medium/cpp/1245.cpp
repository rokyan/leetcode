// https://leetcode.com/problems/tree-diameter/description/

class Solution
{
public:
    int treeDiameter(std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        std::vector<int> dist(n, -1);

        dfs(0, graph, dist, 0);

        const auto v = std::distance(std::cbegin(dist), std::max_element(std::cbegin(dist), std::cend(dist)));

        std::fill(std::begin(dist), std::end(dist), -1);

        dfs(v, graph, dist, 0);

        return *std::max_element(std::cbegin(dist), std::cend(dist));
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<int>& dist, int d)
    {
        dist[v] = d;

        for (auto to : graph[v])
        {
            if (dist[to] == -1)
            {
                dfs(to, graph, dist, d + 1);
            }
        }
    }
};