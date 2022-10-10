// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root)
    {
        std::vector<int> sums;
        
        dfs(root, sums);
        
        return (std::max_element(std::begin(sums), std::end(sums)) - std::begin(sums)) + 1;
    }
    
private:
    void dfs(TreeNode* root, std::vector<int>& sums, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (std::size(sums) == depth)
        {
            sums.push_back(0);
        }
        
        sums[depth] += root->val;
        
        dfs(root->left, sums, depth + 1);
        dfs(root->right, sums, depth + 1);
    }
};