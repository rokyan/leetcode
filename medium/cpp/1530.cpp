// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

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
    int countPairs(TreeNode* root, int distance)
    {
        auto res = 0;

        static_cast<void>(solve(root, distance, res));

        return res;
    }

private:
    std::vector<int> solve(TreeNode* root, int distance, int& res)
    {
        if (root == nullptr)
        {
            return {};
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return { 0 };
        }

        auto left = solve(root->left, distance, res);
        auto right = solve(root->right, distance, res);

        for (auto i = 0; i < std::size(left); i++)
        {
            for (auto j = 0; j < std::size(right); j++)
            {
                if (left[i] + right[j] + 2 <= distance)
                {
                    res++;
                }
            }
        }

        left.insert(std::end(left), std::begin(right), std::end(right));

        for (auto& depth : left)
        {
            depth++;
        }

        return left;
    }
};