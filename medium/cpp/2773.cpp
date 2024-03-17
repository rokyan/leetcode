// https://leetcode.com/problems/height-of-special-binary-tree/description/

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
    int heightOfTree(TreeNode* root)
    {
        return dfs(root);
    }

private:
    int dfs(TreeNode* root, int depth = 0)
    {
        if (root != nullptr && root->left == nullptr && root->right == nullptr)
        {
            return depth;
        }

        if (root != nullptr && root->left != nullptr && root->left->right == root)
        {
            return depth;
        }

        return std::max(root->left != nullptr ? dfs(root->left, depth + 1) : 0, root->right != nullptr ? dfs(root->right, depth + 1) : 0);
    }
};