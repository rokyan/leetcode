// https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }
        else
        {
            dfs(root, 1, depth, val);
            return root;
        }
    }

private:
    void dfs(TreeNode* root, int cur_depth, int depth, int val)
    {
        if (root == nullptr)
        {
            return;
        }

        if (depth == cur_depth + 1)
        {
            auto left = root->left;
            auto right = root->right;
            root->left = new TreeNode(val, left, nullptr);
            root->right = new TreeNode(val, nullptr, right);
        }
        else
        {
            dfs(root->left, cur_depth + 1, depth, val);
            dfs(root->right, cur_depth + 1, depth, val);
        }
    }
};