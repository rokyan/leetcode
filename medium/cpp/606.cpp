// https://leetcode.com/problems/construct-string-from-binary-tree/description/

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
    std::string tree2str(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "";
        }

        auto str = std::to_string(root->val);

        const auto left = tree2str(root->left);
        const auto right = tree2str(root->right);

        if (left == "" && right == "")
        {
            return str;
        }

        if (left == "")
        {
            return str + "()(" + right + ")";
        }

        if (right == "")
        {
            return str + "(" + left + ")";
        }

        return str + "(" + left + ")" + "(" + right + ")";
    }
};