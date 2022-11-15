// https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        return solve(root, target);
    }
    
private:
    TreeNode* solve(TreeNode* node, int target)
    {
        if (node->left != nullptr)
        {
            node->left = solve(node->left, target);
        }
        
        if (node->right != nullptr)
        {
            node->right = solve(node->right, target);
        }
        
        if (is_leaf(node) && node->val == target)
        {
            return nullptr;
        }
        
        return node;
    }
    
    bool is_leaf(TreeNode* node) const
    {
        return node->left == nullptr && node->right == nullptr;
    }
};