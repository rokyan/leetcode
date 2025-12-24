// https://leetcode.com/problems/maximum-subgraph-score-in-a-tree/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    std::vector<int> maxSubgraphScore(int n,
        const std::vector<std::vector<int>>& edges, const std::vector<int>& good)
    {
        const graph_type graph{build_graph(n, edges)};

        std::vector<int> sub_score(n);
        dfs(0, -1, graph, good, sub_score);

        // for (auto e : sub_score) std::cout << e << " "; std::cout << std::endl;

        std::vector<int> res(n);
        dfs2(0, -1, 0, graph, good, sub_score, res);

        return res;
    }

private:
    graph_type build_graph(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void dfs(int v, int p, const graph_type& graph,
        const std::vector<int>& good, std::vector<int>& sub_score)
    {
        for (int to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, graph, good, sub_score);
                sub_score[v] += sub_score[to];
            }
        }

        sub_score[v] += good[v] ? 1 : -1;
        sub_score[v] = std::max(sub_score[v], 0);
    }

    void dfs2(int v, int p, int acc, const graph_type& graph,
        const std::vector<int>& good, std::vector<int>& sub_score,
        std::vector<int>& res)
    {
        int total = 0;

        for (int to : graph[v])
        {
            if (to != p)
            {
                total += sub_score[to];
            }
        }

        res[v] = acc + total + (good[v] ? 1 : -1);

        for (int to : graph[v])
        {
            if (to != p)
            {
                const int n_acc = std::max(0, acc + (good[v] ? 1 : -1) + total - sub_score[to]);
                dfs2(to, v, n_acc, graph, good, sub_score, res);
            }
        }
    }
};