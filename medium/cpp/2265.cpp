// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    int averageOfSubtree(TreeNode* root)
    {
        int answer = 0;
        
        return std::get<2>(solve(root));
    }
    
private:
     std::tuple<int, int, int> solve(TreeNode* root)
     {
         if (root == nullptr)
         {
             return { 0, 0, 0 };
         }
         
         const auto left = solve(root->left);
         const auto right = solve(root->right);
         
         int tot = 1 + std::get<0>(left) + std::get<0>(right);
         int sum = root->val + std::get<1>(left) + std::get<1>(right);
         int answer = std::get<2>(left) + std::get<2>(right);
         
         if (sum / tot == root->val)
         {
             answer++;
         }
         
         return { tot, sum, answer };
     }
};