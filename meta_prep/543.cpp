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
        static_cast<void>(calc_diam(root, res));
        return res;
    }

private:
    int calc_diam(TreeNode* root, int& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto left_len = root->left != nullptr
            ? 1 + calc_diam(root->left, res)
            : 0;
        const auto right_len = root->right != nullptr
            ? 1 + calc_diam(root->right, res)
            : 0;

        res = std::max(res, left_len + right_len);

        return std::max(left_len, right_len);
    }
};