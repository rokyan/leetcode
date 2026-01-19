// https://leetcode.com/problems/minimum-edge-toggles-on-a-tree/description/

class Solution
{
private:
    struct Edge
    {
        Edge(int to, int id)
            : to{to}
            , id{id}
        {}

        int to;
        int id;
    };

    using GraphType = std::vector<std::vector<Edge>>;

public:
    std::vector<int> minimumFlips(int n, const std::vector<std::vector<int>>& edges,
        std::string& start, const std::string& target)
    {
        const GraphType graph{build(n, edges)};

        std::vector<int> res;
        res.reserve(n);

        dfs(0, -1, -1, graph, start, target, res);

        if (start[0] != target[0])
        {
            return { -1 };
        }

        std::ranges::sort(res);

        return res;
    }

private:
    GraphType build(int n, const std::vector<std::vector<int>>& edges)
    {
        GraphType graph(n);

        for (int i = 0; i + 1 < n; i++)
        {
            graph[edges[i][0]].emplace_back(edges[i][1], i);
            graph[edges[i][1]].emplace_back(edges[i][0], i);
        }

        return graph;
    }

    void dfs(int v, int p, int id, const GraphType& graph,
        std::string& start, const std::string& target, std::vector<int>& res)
    {
        for (const Edge& e : graph[v])
        {
            if (e.to != p)
            {
                dfs(e.to, v, e.id, graph, start, target, res);
            }
        }

        if (p != -1)
        {
            if (start[v] != target[v])
            {
                start[v] = target[v];
                start[p] = start[p] == '0' ? '1' : '0';
                res.push_back(id);
            }
        }
    }
};