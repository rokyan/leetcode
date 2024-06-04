// https://leetcode.com/problems/count-nodes-that-are-great-enough/description/

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
    int countGreatEnoughNodes(TreeNode* root, int k)
    {
        auto res = 0;
        static_cast<void>(dfs(root, k, res));
        return res;
    }

private:
    std::multiset<int> dfs(TreeNode* root, int k, int& res)
    {
        if (root == nullptr)
        {
            return {};
        }

        std::multiset<int> values{ root->val };

        const auto left = dfs(root->left, k, res);
        const auto right = dfs(root->right, k, res);

        for (auto num : left)
        {
            values.insert(num);

            if (std::size(values) == k + 1)
            {
                values.erase(--std::cend(values));
            }
        }

        for (auto num : right)
        {
            values.insert(num);

            if (std::size(values) == k + 1)
            {
                values.erase(--std::cend(values));
            }
        }

        if (std::size(values) == k && *std::crbegin(values) < root->val)
        {
            res++;
        }

        return values;
    }
};