// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int maxPathSum(TreeNode* root)
    {
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* root, int& ans)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto lv = dfs(root->left, ans);
        const auto rv = dfs(root->right, ans);

        ans = std::max(ans, lv + root->val + rv);

        return std::max({ 0, root->val + lv, root->val + rv });
    }
};