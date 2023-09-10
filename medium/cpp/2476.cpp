// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/

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
    std::vector<std::vector<int>> closestNodes(TreeNode* root, std::vector<int>& queries)
    {
        const auto qtot = std::size(queries);

        std::vector<std::vector<int>> res(qtot);

        std::vector<int> nums;
        dfs(root, nums);

        for (auto i = 0; i < qtot; i++)
        {
            res[i] = { -1, -1 };

            const auto pos = std::lower_bound(std::begin(nums), std::end(nums), queries[i]) - std::begin(nums);

            if (pos != std::size(nums) && nums[pos] == queries[i])
            {
                res[i] = { nums[pos], nums[pos] };
            }
            else
            {
                if (pos > 0)
                {
                    res[i][0] = nums[pos - 1];
                }

                if (pos != std::size(nums))
                {
                    res[i][1] = nums[pos];
                }
            }
        }

        return res;
    }

private:
    void dfs(TreeNode* root, std::vector<int>& sorted)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left, sorted);

        sorted.push_back(root->val);

        dfs(root->right, sorted);
    }
};