// https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/description/

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
    int equalToDescendants(TreeNode* root)
    {
        auto res = 0;
        static_cast<void>(count(root, res));
        return res;
    }

private:
    long long count(TreeNode* root, int& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto sum = 0LL + count(root->left, res) + count(root->right, res);
        res += sum == root->val;
        return sum + root->val;
    }
};