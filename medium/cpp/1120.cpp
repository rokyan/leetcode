// https://leetcode.com/problems/maximum-average-subtree/description/

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
    double maximumAverageSubtree(TreeNode* root)
    {
        auto res = 0.0;
        go(root, res);
        return res;
    }

private:
    std::pair<int, int> go(TreeNode* root, double& res)
    {
        if (root == nullptr)
        {
            return { 0, 0 };
        }

        auto ret = std::make_pair(root->val, 1);

        const auto lret = go(root->left, res);
        const auto rret = go(root->right, res);

        ret.first += lret.first + rret.first;
        ret.second += lret.second + rret.second;

        res = std::max(res, static_cast<double>(ret.first) / ret.second);

        return ret;
    }
};