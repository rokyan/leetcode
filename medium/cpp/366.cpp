// https://leetcode.com/problems/find-leaves-of-binary-tree/description/

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
    std::vector<std::vector<int>> findLeaves(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        static_cast<void>(go(root, res));
        return res;
    }

private:
    int go(TreeNode* root, std::vector<std::vector<int>>& res)
    {
        if (root == nullptr)
        {
            return -1;
        }

        const auto d = std::max(go(root->left, res), go(root->right, res)) + 1;

        if (std::size(res) == d)
        {
            res.push_back({});
        }

        res[d].push_back(root->val);

        return d;
    }
};