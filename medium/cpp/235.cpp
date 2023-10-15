// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return get_lca(root, p, q);
    }

private:
    TreeNode* get_lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        auto left_subtree_res = get_lca(root->left, p, q);
        auto right_subtree_res = get_lca(root->right, p, q);

        if (left_subtree_res && right_subtree_res)
        {
            return root;
        }

        return right_subtree_res ? right_subtree_res : left_subtree_res;
    }
};