// https://leetcode.com/problems/transform-array-to-all-equal-elements/description/

class Solution
{
public:
    bool canMakeEqual(const std::vector<int>& nums, int k)
    {
        return solve(nums, nums.front(), k) || solve(nums, -nums.front(), k, true);
    }

private:
    bool solve(const std::vector<int>& nums, int val, int k, bool inv = false)
    {
        const auto n = std::size(nums);
        auto mult = 1;
        auto cnt = 0;

        if (inv)
        {
            mult = -1;
            cnt = 1;
        }

        for (auto i = (int)inv; i + 1 < n && cnt <= k; i++)
        {
            if (std::abs(val) != std::abs(nums[i]))
            {
                return false;
            }

            if (mult * nums[i] != val)
            {
                cnt++;
                mult = -1;
            }
            else
            {
                mult = 1;
            }
        }

        if (mult * nums.back() != val)
        {
            return false;
        }

        if (cnt > k)
        {
            return false;
        }

        return true;
    }
};