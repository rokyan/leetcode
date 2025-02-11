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
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        const auto left = lowestCommonAncestor(root->left, p, q);
        const auto right = lowestCommonAncestor(root->right, p, q);

        return left != nullptr && right != nullptr
            ? root
            : left != nullptr
                ? left
                : right;
    }
};