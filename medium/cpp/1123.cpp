// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        return solve(root).first;
    }
    
private:
    std::pair<TreeNode*, int> solve(TreeNode* root, int depth = 0)
    {
        if (root == nullptr)
        {
            return { nullptr, depth };
        }
        
        const auto left_solution = solve(root->left, depth + 1);
        const auto right_solution = solve(root->right, depth + 1);
        
        if (left_solution.second > right_solution.second)
        {
            return left_solution;
        }
        
        if (right_solution.second > left_solution.second)
        {
            return right_solution;
        }
        
        return { root, left_solution.second };
    }
};