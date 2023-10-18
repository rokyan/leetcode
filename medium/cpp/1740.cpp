// https://leetcode.com/problems/find-distance-in-a-binary-tree/description/

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
    int findDistance(TreeNode* root, int p, int q)
    {
        auto pnode = find(root, p);
        auto qnode = find(root, q);
        auto lca = find_lca(root, p, q);

        auto res = 0;
        solve(root, pnode, qnode, lca, res);
        return res;
    }

private:
    TreeNode* find(TreeNode* root, int value)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == value)
        {
            return root;
        }

        auto node = find(root->left, value);

        if (node != nullptr)
        {
            return node;
        }

        return find(root->right, value);
    }

    TreeNode* find_lca(TreeNode* root, int p, int q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == p || root->val == q)
        {
            return root;
        }

        auto left = find_lca(root->left, p, q);
        auto right = find_lca(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }

        return left != nullptr ? left : right;
    }

    void solve(TreeNode* root, TreeNode* pnode, TreeNode* qnode, TreeNode* lca, int& res, int d = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root == pnode)
        {
            res += d;
        }

        if (root == qnode)
        {
            res += d;
        }

        if (root == lca)
        {
            res -= 2 * d;
        }

        solve(root->left, pnode, qnode, lca, res, d + 1);
        solve(root->right, pnode, qnode, lca, res, d + 1);
    }
};