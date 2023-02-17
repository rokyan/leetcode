// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution
{
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> cnt;
        auto dup = 0;
        auto sum = 0LL;
        auto res = 0LL;

        for (auto i = 0; i < std::size(nums); i++)
        {
            cnt[nums[i]]++;

            if (cnt[nums[i]] == 2)
            {
                dup++;
            }

            if (i >= k)
            {
                sum -= nums[i - k];

                cnt[nums[i - k]]--;

                if (cnt[nums[i - k]] == 1)
                {
                    dup--;
                }
            }

            sum += nums[i];

            if (i >= k - 1 && dup == 0)
            {
                res = std::max(res, sum);
            }
        }

        return res;
    }
};