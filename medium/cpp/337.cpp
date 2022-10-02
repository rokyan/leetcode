// https://leetcode.com/problems/house-robber-iii/

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
private:
    using int_pair = std::pair<int, int>;
    
public:
    int rob(TreeNode* root)
    {
        const auto solution = solve(root);
        
        return std::max(solution.first, solution.second);
    }
    
private:
    int_pair solve(TreeNode* root)
    {
        if (root == nullptr)
        {
            return { 0, 0 };
        }
        
        const auto left = solve(root->left);
        const auto right = solve(root->right);
        
        return { root->val + left.second + right.second, std::max(left.first, left.second) + std::max(right.first, right.second) };
    }
};