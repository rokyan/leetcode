// https://leetcode.com/problems/binary-tree-pruning/

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
    TreeNode* pruneTree(TreeNode* root)
    {
        return solve(root);
    }
    
private:
    TreeNode* solve(TreeNode* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        node->left = solve(node->left);
        node->right = solve(node->right);
        
        if (node->left != nullptr || node->right != nullptr)
        {
            return node;
        }
        
        return node->val == 1 ? node : nullptr;
    }
};