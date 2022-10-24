// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        int depth = get_depth(root);
        
        if (depth == 1)
        {
            return 1;
        }
                       
        return solve(root, depth - 1);
    }
    
private:
    int get_depth(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        return 1 + get_depth(node->left);
    }
    
    int solve(TreeNode* node, int depth)
    {
        if (depth == 0)
        {
            return 1;
        }
        
        if (get_depth(node->right) == depth)
        {
            return (1 << depth) + solve(node->right, depth - 1);
        }
        else
        {
            return (1 << (depth - 1)) + solve(node->left, depth - 1);
        }
    }
};