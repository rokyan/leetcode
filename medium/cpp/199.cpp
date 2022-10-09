// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> view;
        
        solve(root, view);
        
        return view;
    }
    
private:
    void solve(TreeNode* node, std::vector<int>& view, int depth = 0)
    {
        if (node == nullptr)
        {
            return;
        }
        
        if (depth == std::size(view))
        {
            view.push_back(node->val);
        }
        
        solve(node->right, view, depth + 1);
        solve(node->left, view, depth + 1);
    }
};