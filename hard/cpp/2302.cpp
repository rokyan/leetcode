// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

class Solution
{
public:
    long long countSubarrays(std::vector<int>& nums, long long k)
    {
        auto res = 0LL;
        auto sum = 0LL;

        for (auto l = 0, r = 0; r < std::size(nums); r++)
        {
            sum += nums[r];

            while (1LL * (r - l + 1) * sum >= k)
            {
                sum -= nums[l++];
            }

            res += r - l + 1;
        }

        return res;
    }
};