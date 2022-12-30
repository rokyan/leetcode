// https://leetcode.com/problems/convert-bst-to-greater-tree/description/

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
    TreeNode* convertBST(TreeNode* root)
    {
        solve(root);
        return root;
    }

private:
    int solve(TreeNode* node, int add = 0)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        const auto right = solve(node->right, add);
        const auto left = solve(node->left, add + node->val + right);
        
        const auto tot = left + right + node->val;
        
        node->val += add + right;
        
        return tot;
    }
};