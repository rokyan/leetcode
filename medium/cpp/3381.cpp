// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/

class Solution
{
public:
    long long maxSubarraySum(const std::vector<int>& nums, int k)
    {
        std::vector<long long> mod(k);
        auto acc = 0LL;

        for (auto i = 0; i + 1 < k; i++)
        {
            acc += nums[i];
            mod[(i + 1) % k] = acc;
        }

        auto res = acc + nums[k - 1];

        for (auto i = k - 1; i < std::size(nums); i++)
        {
            acc += nums[i];
            res = std::max(res, acc - mod[(i + 1) % k]);
            mod[(i + 1) % k] = std::min(mod[(i + 1) % k], acc);
        }

        return res;
    }
};