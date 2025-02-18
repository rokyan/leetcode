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
    std::vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> view;
        traverse(root, view);
        return view;
    }

private:
    void traverse(TreeNode* root, std::vector<int>& view, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        if (std::size(view) == depth)
        {
            view.push_back(root->val);
        }

        traverse(root->right, view, depth + 1);
        traverse(root->left, view, depth + 1);
    }
};