// https://leetcode.com/problems/find-duplicate-subtrees/description/

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
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        std::unordered_map<std::string, int> freq;
        std::vector<TreeNode*> res;

        dfs(root, freq, res);

        return res;
    }

private:
    std::string dfs(TreeNode* root, std::unordered_map<std::string, int>& freq, std::vector<TreeNode*>& res)
    {
        if (root == nullptr)
        {
            return "";
        }

        const auto left = dfs(root->left, freq, res);
        const auto right = dfs(root->right, freq, res);

        const auto repr = "[" + left + "]" + std::to_string(root->val) + "[" + right + "]";

        if (freq[repr]++ == 1)
        {
            res.push_back(root);
        }

        return repr;
    }
};