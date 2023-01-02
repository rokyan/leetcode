// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {   
        pt = std::size(inorder) - 1;
        
        return solve(0, inorder.size(), inorder, postorder);
    }

private:    
    TreeNode* solve(int lf, int rg, const std::vector<int>& inorder, const std::vector<int>& postorder)
    {
        if (lf == rg)
        {
            return nullptr;
        }
        
        auto mid = lf;
        
        while (mid < rg && postorder[pt] != inorder[mid])
        {
            ++mid;
        }
        
        auto node = new TreeNode(postorder[pt--]);
        
        node->right = solve(mid + 1, rg, inorder, postorder);
        node->left = solve(lf, mid, inorder, postorder);
        
        return node;
    }

private:
    int pt = 0;
};