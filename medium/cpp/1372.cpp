// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

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
    int longestZigZag(TreeNode* root)
    {
        auto res = 0;
        static_cast<void>(dfs(root, res));
        return res;
    }

private:
    std::pair<int, int> dfs(TreeNode* root, int& r)
    {
        if (root == nullptr)
        {
            return { 0, 0 };
        }

        auto res = std::make_pair(0, 0);

        if (root->left != nullptr)
        {
            const auto left = dfs(root->left, r);
            res.first = 1 + left.second;
        }

        if (root->right != nullptr)
        {
            const auto right = dfs(root->right, r);
            res.second = 1 + right.first;
        }

        r = std::max(r, std::max(res.first, res.second));

        return res;
    }
};