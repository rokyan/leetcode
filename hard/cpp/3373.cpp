// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/

class Solution
{
public:
    std::vector<int> maxTargetNodes(
        const std::vector<std::vector<int>>& edges1,
        const std::vector<std::vector<int>>& edges2)
    {
        const auto graph1 = build(edges1);
        const auto graph2 = build (edges2);

        std::vector<int> even1(std::size(graph1));
        std::vector<int> odd1(std::size(graph1));

        dfs(0, -1, graph1, even1, odd1);
        dfs2(0, -1, graph1, even1, odd1, 0, 0);

        std::vector<int> even2(std::size(graph2));
        std::vector<int> odd2(std::size(graph2));

        dfs(0, -1, graph2, even2, odd2);
        dfs2(0, -1, graph2, even2, odd2, 0, 0);

        const auto maxVal = *std::max_element(std::cbegin(odd2), std::cend(odd2));

        std::vector<int> res(std::size(graph1));

        for (auto v = 0; v < std::size(graph1); v++)
        {
            res[v] = even1[v] + maxVal;
        }

        return res;
    }

private:
    std::vector<std::vector<int>> build(const std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges);

        std::vector<std::vector<int>> graph(n + 1);

        for (const auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void dfs(int v, int p, const std::vector<std::vector<int>>& graph,
        std::vector<int>& even, std::vector<int>& odd)
    {
        even[v]++;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, graph, even, odd);
                even[v] += odd[to];
                odd[v] += even[to];
            }
        }
    }

    void dfs2(int v, int p, const std::vector<std::vector<int>>& graph,
        std::vector<int>& even, std::vector<int>& odd,
        int carryEven, int carryOdd)
    {
        even[v] += carryEven;
        odd[v] += carryOdd;
        
        auto curEven = 0;
        auto curOdd = 0;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                curEven += even[to];
                curOdd += odd[to];
            }
        }

        for (auto to : graph[v])
        {
            if (to != p)
            {
                const auto oldEven = curEven;
                const auto oldOdd = curOdd;

                curEven -= even[to];
                curOdd -= odd[to];

                dfs2(to, v, graph, even, odd, carryOdd + curEven, carryEven + curOdd + 1);

                curOdd = oldOdd;
                curEven = oldEven;
            }
        }
    }
};