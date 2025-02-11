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
    int diameterOfBinaryTree(TreeNode* root)
    {
        auto res = 0;
        calc_diam(root, res);
        return res;
    }

private:
    int calc_diam(TreeNode* root, int& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto left_len = calc_diam(root->left, res);
        const auto right_len = calc_diam(root->right, res);
        res = std::max(res, left_len + right_len);
        return 1 + std::max(left_len, right_len);
    }
};