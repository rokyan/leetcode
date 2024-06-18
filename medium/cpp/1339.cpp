// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

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
    int maxProduct(TreeNode* root)
    {
        const auto s = sum(root);
        auto res = 0LL;
        dfs(root, s, res);
        return res % 1000'000'007;
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

    int dfs(TreeNode* root, int s, long long& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto cur = root->val + dfs(root->left, s, res) + dfs(root->right, s, res);
        res = std::max(res, 1LL * cur * (s - cur));
        return cur;
    }
};