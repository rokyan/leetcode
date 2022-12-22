// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    int goodNodes(TreeNode* root)
    {
        return solve(root, root->val);
    }
    
private:
    int solve(TreeNode* root, int greatest)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        const auto upd = std::max(greatest, root->val);
        const auto count = solve(root->left, upd) + solve(root->right, upd);
        
        return count + (root->val >= greatest);
    }
};