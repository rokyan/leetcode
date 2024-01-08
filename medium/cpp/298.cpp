// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/

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
    int longestConsecutive(TreeNode* root)
    {
        auto res = 0;
        search(root, res);
        return res;
    }

private:
    int search(TreeNode* root, int& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto r_len = search(root->right, res);
        const auto l_len = search(root->left, res);

        auto cur = 1;

        if (root->right != nullptr && root->val + 1 == root->right->val)
        {
            cur = std::max(cur, 1 + r_len);
        }

        if (root->left != nullptr && root->val + 1 == root->left->val)
        {
            cur = std::max(cur, 1 + l_len);
        }

        res = std::max(res, cur);

        return cur;
    }
};