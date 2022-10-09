// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        return dfs(root).second;
    }
    
private:
    std::pair<int, TreeNode*> dfs(TreeNode* node)
    {
        if (node == nullptr)
        {
            return { 0, nullptr };
        }
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        if (left.first > right.first)
        {
            return { left.first + 1, left.second };
        }
        else if (left.first < right.first)
        {
            return { right.first + 1, right.second };
        }
            
        return { left.first + 1, node };
    }
};