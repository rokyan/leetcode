// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

class Solution
{
public:
    std::vector<int> countSubTrees(int n, std::vector<std::vector<int>>& edges, std::string labels)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> res(n);

        dfs(0, -1, graph, labels, res);

        return res;
    }

private:
    std::vector<int> dfs(int v, int p, const std::vector<std::vector<int>>& graph, const std::string& labels, std::vector<int>& res)
    {
        std::vector<int> acc(26);

        for (auto to : graph[v])
        {
            if (to != p)
            {
                const auto t = dfs(to, v, graph, labels, res);

                for (auto i = 0; i < 26; i++)
                {
                    acc[i] += t[i];
                }
            }
        }

        acc[labels[v] - 'a']++;
        res[v] += acc[labels[v] - 'a'];

        return acc;
    }
};