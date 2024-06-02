// https://leetcode.com/problems/delete-tree-nodes/description/

class Solution
{
private:
    struct state
    {
        int sum;
        int count;
    };

public:
    int deleteTreeNodes(int nodes, std::vector<int>& parent, std::vector<int>& value)
    {
        std::vector<std::vector<int>> graph(nodes);

        for (auto i = 0; i < nodes; i++)
        {
            if (i > 0)
            {
                graph[parent[i]].push_back(i);
            }
        }

        return dfs(0, graph, value).count;
    }

private:
    state dfs(int v, const std::vector<std::vector<int>>& graph, const std::vector<int>& value)
    {
        auto sum = value[v];
        auto count = 1;

        for (auto to : graph[v])
        {
            const auto c = dfs(to, graph, value);
            sum += c.sum;
            count += c.count;
        }

        if (sum == 0)
        {
            return state{ 0, 0 };
        }

        return state{ sum, count };
    }
};