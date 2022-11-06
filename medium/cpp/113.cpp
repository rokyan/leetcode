// https://leetcode.com/problems/path-sum-ii/

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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
        {
            return {};
        }
        
        std::vector<int> path;
        std::vector<std::vector<int>> paths;
        
        solve(root, path, paths, 0, targetSum);
        
        return paths;
    }
    
private:
    void solve(TreeNode* node, std::vector<int>& path, std::vector<std::vector<int>>& paths, int sum, int targetSum)
    {  
        sum += node->val;
        path.push_back(node->val);
        
        if (is_leaf(node))
        {           
            if (sum == targetSum)
            {
                paths.push_back(path);
            }
        }
        else
        {            
            if (node->left != nullptr)
            {
                solve(node->left, path, paths, sum, targetSum);
            }
            
            if (node->right != nullptr)
            {
                solve(node->right, path, paths, sum, targetSum);
            }
        }
        
        path.pop_back();
    }
    
    bool is_leaf(TreeNode* node)
    {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
};