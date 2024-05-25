// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/description/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, std::vector<TreeNode*> &nodes)
    {
        return lca(root, nodes);
    }

private:
    TreeNode* lca(TreeNode* root, const std::vector<TreeNode*> &nodes)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        for (auto node : nodes)
        {
            if (node == root)
            {
                return root;
            }
        }

        auto left = lca(root->left, nodes);
        auto right = lca(root->right, nodes);

        if (left && right)
        {
            return root;
        }

        return left == nullptr ? right : left;
    }
};