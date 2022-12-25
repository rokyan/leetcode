// https://leetcode.com/problems/maximum-binary-tree/description/

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
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
    {
        return solve(nums, 0, std::size(nums));
    }
    
private:
    TreeNode* solve(const std::vector<int>& nums, int left, int right)
    {
        auto maxPos = left;
        auto maxNum = nums[left];
        
        for (int pos = left; pos < right; pos++)
        {
            if (nums[pos] > maxNum)
            {
                maxNum = nums[pos];
                maxPos = pos;
            }
        }
        
        TreeNode* node = new TreeNode(maxNum);
        
        if (left < maxPos)
        {
            node->left = solve(nums, left, maxPos);
        }
        
        if (maxPos + 1 < right)
        {
            node->right = solve(nums, maxPos + 1, right);
        }
        
        return node;
    }
};