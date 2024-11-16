// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/

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
private:
    struct state
    {
        int inc = 0;
        int dec = 0;
    };

public:
    int longestConsecutive(TreeNode* root)
    {
        dfs(root);
        return res;
    }

private:
    state dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }

        const auto left = dfs(root->left);
        const auto right = dfs(root->right);

        if (root->left != nullptr && root->right != nullptr)
        {
            auto len = 1;

            if (root->left->val + 1 == root->val)
            {
                len += left.inc;
            }

            if (root->right->val - 1 == root->val)
            {
                len += right.dec;
            }

            res = std::max(res, len);

            len = 1;

            if (root->left->val - 1 == root->val)
            {
                len += left.dec;
            }

            if (root->right->val + 1 == root->val)
            {
                len += right.inc;
            }

            res = std::max(res, len);
        }
        else if (root->left != nullptr)
        {
            if (root->left->val + 1 == root->val)
            {
                res = std::max(res, 1 + left.inc);
            }

            if (root->left->val - 1 == root->val)
            {
                res = std::max(res, 1 + left.dec);
            }
        }
        else if (root->right != nullptr)
        {
            if (root->right->val + 1 == root->val)
            {
                res = std::max(res, 1 + right.inc);
            }

            if (root->right->val - 1 == root->val)
            {
                res = std::max(res, 1 + right.dec);
            }       
        }

        auto s = state{1, 1};

        if (root->left != nullptr)
        {
            if (root->left->val + 1 == root->val)
            {
                s.inc = std::max(s.inc, left.inc + 1);
            }

            if (root->left->val - 1 == root->val)
            {
                s.dec = std::max(s.dec, left.dec + 1);
            }
        }

        if (root->right != nullptr)
        {
            if (root->right->val + 1 == root->val)
            {
                s.inc = std::max(s.inc, right.inc + 1);
            }

            if (root->right->val - 1 == root->val)
            {
                s.dec = std::max(s.dec, right.dec + 1);
            }
        }

        return s;
    }

private:
    int res = 1;
};