// https://leetcode.com/problems/find-bottom-left-tree-value/description/

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
    int findBottomLeftValue(TreeNode* root)
    {
        auto res = 0;
        auto maxDepth = -1;

        solve(root, res, maxDepth);

        return res;
    }

private:    
    void solve(TreeNode* node, int& res, int& maxDepth, int depth = 0)
    {
        if (node == nullptr)
        {
            return;
        }
        
        if (maxDepth < depth)
        {
            maxDepth = depth;
            res = node->val;
        } 
        
        solve(node->left, res, maxDepth, depth + 1);
        solve(node->right, res, maxDepth, depth + 1);
    }
};