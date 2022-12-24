// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

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
    int sumEvenGrandparent(TreeNode* root)
    {
        return solve(root, nullptr, nullptr);
    }
    
private:
    int solve(TreeNode* root, TreeNode* parent, TreeNode* grandparent)
    {
        int answer = 0;
        
        if (root == nullptr)
        {
            return answer;
        }
        
        if (grandparent != nullptr && grandparent->val % 2 == 0)
        {
            answer += root->val;
        }
        
        if (root->left != nullptr)
        {
            answer += solve(root->left, root, parent);
        }
        
        if (root->right != nullptr)
        {
            answer += solve(root->right, root, parent);
        }
        
        return answer;
    }
};