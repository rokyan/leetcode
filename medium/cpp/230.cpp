// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k)
    {
        std::unordered_map<TreeNode*, int> sizes;
        sizes[nullptr] = 0;
        
        fill_sizes(root, sizes);
        
        return solve(root, k, sizes)->val;
    }
    
private:
    void fill_sizes(TreeNode* node, std::unordered_map<TreeNode*, int>& sizes)
    {
        if (node == nullptr)
        {
            return;
        }
        
        fill_sizes(node->left, sizes);
        fill_sizes(node->right, sizes);
        
        sizes[node] = 1 + sizes[node->left] + sizes[node->right];
    }
    
    TreeNode* solve(TreeNode* node, int k, std::unordered_map<TreeNode*, int>& sizes)
    {
        const auto left_subtree_size = sizes[node->left];
        
        if (left_subtree_size >= k)
        {
            return solve(node->left, k, sizes);
        }
        else if (left_subtree_size + 1 < k)
        {
            return solve(node->right, k - left_subtree_size - 1, sizes);
        }
        else
        {
            return node;
        }
    }   
};