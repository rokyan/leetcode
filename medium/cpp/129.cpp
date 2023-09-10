// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int sumNumbers(TreeNode* root)
    {
        return solve(root);
    }

private:   
    int solve(TreeNode* node, int sum = 0) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        const auto upd = 10 * sum + node->val;
        
        if (isLeaf(node))
        {
            return upd;
        }
        
        return solve(node->left, upd) + solve(node->right, upd);
    }

    bool isLeaf(TreeNode* node) const
    {
        return node->left == nullptr && node->right == nullptr;
    }
};