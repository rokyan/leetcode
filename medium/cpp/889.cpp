// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        return build(preorder, 0, std::size(preorder), postorder, 0, std::size(postorder));
    }
    
private:
    TreeNode* build(const std::vector<int>& preorder, std::size_t pre_l, std::size_t pre_r,
        const std::vector<int>& postorder, std::size_t post_l, std::size_t post_r)
    {       
        if (pre_l == pre_r)
        {
            return nullptr;
        }
        
        if (pre_l + 1 == pre_r)
        {
            return new TreeNode(preorder[pre_l]);
        }
        
        TreeNode* node = new TreeNode(preorder[pre_l]);
        
        int count = 1;
        
        while (postorder[post_l + count - 1] != preorder[pre_l + 1])
        {
            count++;
        }
        
        node->left = build(preorder, pre_l + 1, pre_l + count + 1, postorder, post_l, post_l + count);
        node->right = build(preorder, pre_l + count + 1, pre_r, postorder, post_l + count, post_r - 1);
        
        return node;
    }
};