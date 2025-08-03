// https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/description/

class Solution
{
public:
    int minCost(const std::vector<int>& nums)
    {
        dp.resize(std::size(nums), std::vector<int>(std::size(nums), -1));
        return calc(1, 0, nums);
    }

private:
    int calc(int pos, int carry, const std::vector<int>& nums)
    {
        const auto rem = std::size(nums) - pos + 1;

        if (rem == 1)
        {
            return nums[carry];
        }

        if (rem == 2)
        {
            return std::max(nums[carry], nums[pos]);
        }

        if (dp[carry][pos] != -1)
        {
            return dp[carry][pos];
        }

        return dp[carry][pos] = std::min({
            calc(pos + 2, carry, nums) + std::max(nums[pos], nums[pos + 1]),
            calc(pos + 2, pos, nums) + std::max(nums[carry], nums[pos + 1]),
            calc(pos + 2, pos + 1, nums) + std::max(nums[pos], nums[carry])
        });
    }

private:
    std::vector<std::vector<int>> dp;
};