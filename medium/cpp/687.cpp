// https://leetcode.com/problems/longest-univalue-path/description/

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
    int longestUnivaluePath(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        auto res = 0;
        dfs(root, res);
        return res - 1;
    }

private:
    int dfs(TreeNode* root, int& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        auto pl = 1;

        const auto ls_res = dfs(root->left, res);
        const auto rs_res = dfs(root->right, res);

        if (root->left && root->right && root->left->val == root->val && root->right->val == root->val)
        {
            res = std::max(res, 1 + ls_res + rs_res);
            pl = std::max(pl, 1 + ls_res);
            pl = std::max(pl, 1 + rs_res);
        }
        else if (root->left && root->left->val == root->val)
        {
            pl = std::max(pl, 1 + ls_res);
            res = std::max(res, 1 + ls_res);
        }
        else if (root->right && root->right->val == root->val)
        {
            pl = std::max(pl, 1 + rs_res);
            res = std::max(res, 1 + rs_res);
        }
        else
        {
            res = std::max(res, 1);
        }

        return pl;
    }
};