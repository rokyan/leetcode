/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        const auto graph = build(root);

        std::vector<int> res;
        dfs(target, nullptr, k, graph, res);

        return res;
    }

private:
    std::unordered_map<TreeNode*, std::vector<TreeNode*>> build(TreeNode* root)
    {
        std::unordered_map<TreeNode*, std::vector<TreeNode*>> graph;
        graph[root] = {};
        build(root, nullptr, graph);
        return graph;
    }

    void build(TreeNode* root, TreeNode* parent,
        std::unordered_map<TreeNode*, std::vector<TreeNode*>>& graph)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left != nullptr)
        {
            graph[root].push_back(root->left);
        }

        if (root->right != nullptr)
        {
            graph[root].push_back(root->right);
        }

        if (parent != nullptr)
        {
            graph[root].push_back(parent);
        }

        build(root->left, root, graph);
        build(root->right, root, graph);
    }

    void dfs(TreeNode* root, TreeNode* parent, int depth,
        const std::unordered_map<TreeNode*, std::vector<TreeNode*>>& graph,
        std::vector<int>& res)
    {
        if (root == nullptr)
        {
            return;
        }

        if (depth == 0)
        {
            res.push_back(root->val);
        }

        for (auto to : graph.at(root))
        {
            if (to != parent)
            {
                dfs(to, root, depth - 1, graph, res);
            }
        }
    }
};