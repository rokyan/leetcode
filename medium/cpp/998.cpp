// https://leetcode.com/problems/maximum-binary-tree-ii/

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val)
    {
        return solve(root, val);
    }
    
private:
    TreeNode* solve(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        
        if (val > root->val)
        {
            auto node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        root->right = solve(root->right, val);
        
        return root;
    }
};