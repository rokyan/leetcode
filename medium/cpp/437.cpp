// https://leetcode.com/problems/path-sum-iii/description/

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
    int pathSum(TreeNode* root, int targetSum)
    {
        auto res = 0;
        auto counts = dfs(root, 0LL, targetSum, res);

        if (auto it = counts.find(targetSum); it != std::end(counts))
        {
            res += it->second;
        }

        return res;
    }

private:
    std::unordered_map<long long, int> dfs(TreeNode* root, long long sum, int targetSum, int& res)
    {
        if (root == nullptr)
        {
            return {};
        }

        sum += root->val;

        const auto left = dfs(root->left, sum, targetSum, res);
        const auto right = dfs(root->right, sum, targetSum, res);

        std::unordered_map<long long, int> cur;

        for (const auto& e : left)
        {
            cur[e.first] += e.second;
        }

        for (const auto& e : right)
        {
            cur[e.first] += e.second;
        }

        if (const auto it = cur.find(targetSum + sum); it != std::end(cur))
        {
            res += it->second;
        }

        cur[sum]++;

        return cur;
    }
};