// https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    int maxKDivisibleComponents(int n, const std::vector<std::vector<int>>& edges,
        std::vector<int>& values, int k)
    {
        const auto graph = build(edges);

        std::vector<int> parent(std::size(graph));
        std::vector<vector<int>> levels;

        dfs(0, -1, 0, graph, parent, levels);

        auto res = 0;

        for (int i = std::size(levels) - 1; i >= 0; i--)
        {
            for (auto v : levels[i])
            {
                if (values[v] % k == 0)
                {
                    res++;
                }
                else
                {
                    values[parent[v]] += values[v];
                    values[parent[v]] %= k;
                }
            }
        }


        return res;
    }

private:
    graph_type build(const std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges) + 1;

        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void dfs(int v, int p, int d, const graph_type& graph, 
        std::vector<int>& parent, std::vector<vector<int>>& levels)
    {
        parent[v] = p;
        
        if (std::size(levels) == d)
        {
            levels.push_back({});
        }

        levels[d].push_back(v);

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, d + 1, graph, parent, levels);
            }
        }
    }
};