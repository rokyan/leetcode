// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/

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
    int minimumOperations(TreeNode* root)
    {
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({ root, 0 });

        auto level = 0;
        auto res = 0;

        std::vector<int> nums;

        while (!q.empty())
        {
            const auto state = q.front();
            q.pop();

            if (state.second > level)
            {
                level = state.second;
                res += calc(nums);
                nums.clear();
            }

            nums.push_back(state.first->val);

            if (state.first->left != nullptr)
            {
                q.push({ state.first->left, state.second + 1 });
            }

            if (state.first->right != nullptr)
            {
                q.push({ state.first->right, state.second + 1 });
            }
        }

        res += calc(nums);

        return res;
    }

private:
    int calc(std::vector<int>& nums)
    {
        std::map<int, int> remap;

        for (auto num : nums)
        {
            remap[num] = 0;
        }

        auto cnt = 0;

        for (auto& entry : remap)
        {
            entry.second = cnt++;
        }

        for (auto i = 0; i < std::size(nums); i++)
        {
            nums[i] = remap[nums[i]];
        }

        std::vector<bool> used(std::size(nums));

        auto res = 0;

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (!used[i])
            {
                used[i] = true;

                auto j = nums[i];

                while (!used[j])
                {
                    res++;
                    used[j] = true;
                    j = nums[j];
                }
            }
        }

        return res;
    }
};