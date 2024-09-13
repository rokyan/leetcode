// https://leetcode.com/problems/equal-tree-partition/description/

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
    bool checkEqualTree(TreeNode* root)
    {
        auto solved = false;

        solve(root, sum(root), solved);

        return solved;
    }

private:
    int sum(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return root->val + sum(root->left) + sum(root->right);
    }

    int solve(TreeNode* root, int sum, bool& solved)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto ls = solve(root->left, sum, solved);

        if (ls == sum - ls && root->left)
        {
            solved = true;
        }

        const auto rs = solve(root->right, sum, solved);

        if (rs == sum - rs && root->right)
        {
            solved = true;
        }

        return root->val + ls + rs;
    }
};