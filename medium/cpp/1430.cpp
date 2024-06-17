// https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/description/

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
    bool isValidSequence(TreeNode* root, std::vector<int>& arr)
    {
        return dfs(root, arr);
    }

private:
    bool dfs(TreeNode* root, const std::vector<int>& arr, std::size_t pos = 0)
    {
        if (pos + 1 == std::size(arr))
        {
            return root != nullptr &&
                root->val == arr.back() &&
                root->left == nullptr &&
                root->right == nullptr;
        }

        if (root == nullptr)
        {
            return false;
        }

        if (root->val != arr[pos])
        {
            return false;
        }

        return dfs(root->left, arr, pos + 1) || dfs(root->right, arr, pos + 1);
    }
};