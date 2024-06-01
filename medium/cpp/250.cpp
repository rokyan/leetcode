// https://leetcode.com/problems/count-univalue-subtrees/description/

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
    int countUnivalSubtrees(TreeNode* root)
    {
        return dfs(root).first;
    }

private:
    std::pair<int, bool> dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return { 0, true };
        }

        const auto left = dfs(root->left);
        const auto right = dfs(root->right);

        auto univalue = left.second && right.second &&
            (root->left == nullptr || root->left->val == root->val) &&
            (root->right == nullptr || root->right->val == root->val);

        return { left.first + right.first + univalue, univalue };
    }
};