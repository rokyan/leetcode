// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode* root)
    {
        build(root);
    }

private:
    void build(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        
        build(node->left);
        build(node->right);
        
        auto runner = node;
        auto prev = runner->right;
        
        runner->right = runner->left;
        runner->left = nullptr;
        
        while (runner->right != nullptr)
        {
            runner = runner->right;
        }
        
        runner->right = prev;
    }
};