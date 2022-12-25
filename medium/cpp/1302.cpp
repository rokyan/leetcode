// https://leetcode.com/problems/deepest-leaves-sum/description/

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
    int deepestLeavesSum(TreeNode* root)
    {
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0 });

        auto  level = 0;
        auto ans = 0;
        
        while (!q.empty())
        {
            const auto v = q.front();
            q.pop();
            
            if (v.second == level)
            {
                ans += v.first->val;
            }
            else if (v.second > level)
            {
                level = v.second;
                ans = v.first->val;
            }
            
            if (v.first->left != nullptr)
            {
                q.push({ v.first->left, v.second + 1 });
            }
            
            if (v.first->right != nullptr)
            {
                q.push({ v.first->right, v.second + 1 });
            }
        }
        
        return ans;
    }
};