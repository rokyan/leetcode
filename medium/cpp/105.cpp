// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        return solve(0, std::size(preorder), preorder, inorder);
    }

private:    
    TreeNode* solve(int lf, int rg, const std::vector<int>& preorder, const std::vector<int>& inorder)
    {
        if (lf == rg)
        {
            return nullptr;
        }
        
        auto mid = lf;
        
        while (mid < rg && inorder[mid] != preorder[pt])
        {
            ++mid;
        }

        auto node = new TreeNode(preorder[pt++]);
        
        node->left = solve(lf, mid, preorder, inorder);
        node->right = solve(mid + 1, rg, preorder, inorder);
        
        return node;
    }

private:
    int pt = 0;
};