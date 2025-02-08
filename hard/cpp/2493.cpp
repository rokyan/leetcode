// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;
 
public:
    int magnificentSets(int n, const std::vector<std::vector<int>>& edges)
    {
        const auto graph = transform_to_graph(n, edges);

        std::vector<char> visited(n);

        auto res = 0;

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                const auto nodes = visit(v, graph, visited);

                auto comp_res = -1;

                for (auto sv : nodes)
                {
                    comp_res = std::max(comp_res, check(sv, n, graph));
                }

                if (comp_res == -1)
                {
                    return -1;
                }

                res += comp_res;
            }
        }

        return res;
    }

private:
    graph_type transform_to_graph(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        return graph;
    }

    std::vector<int> visit(int v, const graph_type& graph, std::vector<char>& visited)
    {
        std::vector<int> nodes;
        std::queue<int> q;
        q.push(v);

        while (!q.empty())
        {
            const auto u = q.front();
            q.pop();
            visited[u] = true;
            nodes.push_back(u);

            for (const auto to : graph[u])
            {
                if (!visited[to])
                {
                    visited[to] = true;
                    q.push(to);
                }
            }
        }

        return nodes;
    }

    int check(int v, int n, const graph_type& graph)
    {
        std::queue<int> q;
        q.push(v);

        std::vector<int> colors(n);
        colors[v] = 1;

        auto res = -1;

        while (!q.empty())
        {
            const auto u = q.front();
            q.pop();
            res = std::max(res, colors[u]);

            for (const auto to : graph[u])
            {
                if (!colors[to])
                {
                    colors[to] = colors[u] + 1;
                    q.push(to);
                }
                else if (colors[to] != colors[u] - 1 && colors[to] != colors[u] + 1)
                {
                    return -1;
                }
            }
        }

        return res;
    }
};