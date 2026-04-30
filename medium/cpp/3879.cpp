// https://leetcode.com/problems/maximum-distinct-path-sum-in-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    int maxSum(TreeNode* root)
    {
        const auto [graph, values] = build_graph(root);

        int res = -1000'000'000;

        for (int v = 0; v < values.size(); v++)
        {
            std::unordered_set<int> probe;
            res = std::max(res, dfs2(graph, values, v, -1, probe));
        }

        return res;
    }

private:
    std::tuple<graph_type, std::vector<int>> build_graph(TreeNode* root)
    {
        graph_type graph;
        std::vector<int> values;

        int v = -1;

        dfs(root, graph, values, v);

        return std::make_tuple(graph, values);
    }

    void dfs(TreeNode* root, graph_type& graph, std::vector<int>& values,
        int& v, int prev = -1)
    {
        if (root == nullptr)
        {
            return;
        }

        values.push_back(root->val);
        graph.push_back({});

        v++;

        if (prev != -1)
        {
            graph[prev].push_back(v);
            graph[v].push_back(prev);
        }

        const int cur = v;

        dfs(root->left, graph, values, v, cur);
        dfs(root->right, graph, values, v, cur);
    }

    int dfs2(const graph_type& graph, const std::vector<int>& values,
        int v, int prev, std::unordered_set<int>& probe)
    {
        if (!probe.insert(values[v]).second)
        {
            return 0;
        }

        int maxSum = 0;

        for (const auto to : graph[v])
        {
            if (to != prev)
            {
                maxSum = std::max(maxSum, dfs2(graph, values, to, v, probe));
            }
        }

        probe.erase(values[v]);

        return maxSum + values[v];
    }
};