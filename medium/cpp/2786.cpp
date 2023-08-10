// https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/

class Solution
{
public:
    long long maxScore(vector<int>& nums, int x)
    {
        auto odd = 0LL;
        auto even = 0LL;
        auto res = 0LL;

        for (auto pos = std::size(nums) - 1; pos > 0; pos--)
        {
            if (nums[pos] & 1)
            {
                odd = std::max(odd + nums[pos], even + nums[pos] - x);
            }
            else
            {
                even = std::max(even + nums[pos], odd + nums[pos] - x);
            }

            if (nums[0] & 1)
            {
                const auto val = std::max(nums[0] + odd, nums[0] + even - x);
                res = std::max(res, val);
            }
            else
            {
                const auto val = std::max(nums[0] + even, nums[0] + odd - x);
                res = std::max(res, val);
            }
        }

        return res;
    }
};