// https://leetcode.com/problems/split-bst/description/

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
    std::vector<TreeNode*> splitBST(TreeNode* root, int target)
    {
        return solve(root, target);
    }

private:
    std::vector<TreeNode*> solve(TreeNode* root, int target)
    {
        if (root == nullptr)
        {
            return { nullptr, nullptr };
        }

        if (root->val <= target)
        {
            auto res = solve(root->right, target);
            root->right = res[0];
            return { root, res[1] };
        }
        else
        {
            auto res = solve(root->left, target);
            root->left = res[1];
            return { res[0], root };
        }
    }
};