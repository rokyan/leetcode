// https://leetcode.com/problems/minimum-increments-to-equalize-leaf-paths/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    int minIncrease(int n, const std::vector<std::vector<int>>& edges, const std::vector<int>& cost)
    {
        const auto graph = build(edges);
        const auto maxCost = calcMaxCost(0, -1, graph, cost);
        int res = 0;
        calcMinIncrease(0, -1, graph, 0, maxCost, cost, res);
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

    long long calcMaxCost(int v, int p, const graph_type& graph, const std::vector<int>& cost)
    {
        auto maxCost = 0LL;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                maxCost = std::max(maxCost, calcMaxCost(to, v, graph, cost));
            }
        }

        return maxCost + cost[v];
    }

    int calcMinIncrease(int v, int p, const graph_type& graph,
        long long acc, long long maxCost, const std::vector<int>& cost, int& res)
    {
        acc += cost[v];

        if (1 == std::size(graph[v]) && graph[v].front() == p)
        {
            if (acc < maxCost)
            {
                res++;
            }

            return maxCost - acc;
        }

        std::vector<long long> adds;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                const auto val = calcMinIncrease(to, v, graph, acc, maxCost, cost, res);
                adds.push_back(val);
            }
        }

        const auto minVal = *std::min_element(std::cbegin(adds), std::cend(adds));

        if (minVal == 0)
        {
            return 0;
        }

        for (auto e : adds)
        {
            if (e == minVal)
            {
                res--;
            }
        }

        res++;

        return minVal;
    }
};