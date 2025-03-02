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
    int closestValue(TreeNode* root, double target)
    {
        auto diff = std::abs(root->val - target);
        auto res = root->val;
        find(root, target, diff, res);
        return res;
    }

private:
    void find(TreeNode* root, double target, double& diff, int& res)
    {
        if (root == nullptr)
        {
            return;
        }

        const auto curDiff = std::abs(root->val - target);

        if (curDiff < diff || curDiff == diff && root->val < res)
        {
            diff = curDiff;
            res = root->val;
        }

        if (target < root->val)
        {
            find(root->left, target, diff, res);
        }
        else
        {
            find(root->right, target, diff, res);
        }
    }
};