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
    int sumNumbers(TreeNode* root)
    {
        return solve(root);
    }

private:
    int solve(TreeNode* root, int num = 0)
    {
        num = 10 * num + root->val;

        if (isLeaf(root))
        {
            return num;
        }

        auto sum = 0;
        
        if (root->left != nullptr) sum += solve(root->left, num);
        if (root->right != nullptr) sum += solve(root->right, num);

        return sum;
    }

    bool isLeaf(TreeNode* root)
    {
        return root != nullptr &&
            root->left == nullptr && root->right == nullptr;
    }
};