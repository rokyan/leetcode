// https://leetcode.com/problems/most-frequent-subtree-sum/description/

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
    std::vector<int> findFrequentTreeSum(TreeNode* root)
    {
        std::unordered_map<int, int> counts;
        static_cast<void>(traverse(root, counts));

        auto freq = 0;
        std::vector<int> res;

        for (auto&& entry : counts)
        {
            if (entry.second > freq)
            {
                freq = entry.second;
                res = { entry.first };
            }
            else if (entry.second == freq)
            {
                res.push_back(entry.first);
            }
        }

        return res;
    }

private:
    int traverse(TreeNode* root, std::unordered_map<int, int>& counts)
    {
        if (root == nullptr)
        {
            return 0;
        }

        const auto sum = root->val + traverse(root->left, counts) + traverse(root->right, counts);

        counts[sum]++;

        return sum;
    }
};