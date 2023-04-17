// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

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
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        dfs(root);
        dfs2(root);

        root->val = 0;

        return root;
    }

private:
    void dfs(TreeNode* root, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (depth == std::size(sum))
        {
            sum.push_back(0);
        }

        sum[depth] += root->val;

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    void dfs2(TreeNode* root, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        auto sub = 0;

        if (root->left != nullptr)
        {
            sub += root->left->val;
        }

        if (root->right != nullptr)
        {
            sub += root->right->val;
        }

        if (root->left != nullptr)
        {
            root->left->val = sum[depth + 1] - sub;
        }

        if (root->right != nullptr)
        {
            root->right->val = sum[depth + 1] - sub;
        }

        dfs2(root->left, depth + 1);
        dfs2(root->right, depth + 1);
    }

private:
    std::vector<int> sum;
};