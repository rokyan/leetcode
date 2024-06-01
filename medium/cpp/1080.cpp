// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/

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
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit)
    {
        return dfs(root, limit).second;
    }

private:
    std::pair<int, TreeNode*> dfs(TreeNode* node, int limit, int s = 0)
    {
        s += node->val;

        if (node->left == nullptr && node->right == nullptr)
        {
            if (s < limit)
            {
                return { s, nullptr };
            }

            return { s, node };
        }

        auto m = -111111;

        if (node->left != nullptr)
        {
            const auto res = dfs(node->left, limit, s);
            m = std::max(m, res.first);
            node->left = res.second;
        }

        if (node->right != nullptr)
        {
            const auto res = dfs(node->right, limit, s);
            m = std::max(m, res.first);
            node->right = res.second;
        }

        if (m < limit)
        {
            return { m, nullptr };
        }

        return { m, node };
    }
};