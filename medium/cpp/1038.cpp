// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    TreeNode* bstToGst(TreeNode* root)
    {
        dfs1(root);
        dfs2(root);
        
        return root;
    }
    
private:
    int dfs1(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        int right_sum = dfs1(root->right);
        int left_sum = dfs1(root->left);
        
        root->val += right_sum;
        
        return root->val + left_sum;
    }
    
    void dfs2(TreeNode* root, int val = 0)
    {
        if (root == nullptr)
        {
            return;
        }
        
        dfs2(root->left, val + root->val);
        dfs2(root->right, val);
        
        root->val += val;
    }
};