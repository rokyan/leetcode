// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    TreeNode* bstFromPreorder(std::vector<int>& preorder)
    {
        return solve(preorder, std::size_t(0), std::size(preorder));
    }
    
private:
    TreeNode* solve(const std::vector<int>& preorder, std::size_t left, std::size_t right)
    {
        TreeNode* node = new TreeNode(preorder[left++]);
        
        auto mid = left;
        
        while (mid < right && preorder[mid] < node->val)
        {
            mid++;
        }
        
        if (mid > left)
        {
            node->left = solve(preorder, left, mid);
        }
        
        if (right > mid)
        {
            node->right = solve(preorder, mid, right);
        }
        
        return node;
    }
};