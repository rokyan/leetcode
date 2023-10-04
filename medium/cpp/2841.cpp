// https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/

class Solution
{
public:
    long long maxSum(std::vector<int>& nums, int m, int k)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, int> cnt;

        auto s = 0LL;

        for (auto i = 0; i + 1 < k; i++)
        {
            cnt[nums[i]]++;
            s += nums[i];
        }

        auto res = 0LL;

        for (auto i = k - 1; i < n; i++)
        {
            cnt[nums[i]]++;
            s += nums[i];

            if (std::size(cnt) >= m)
            {
                res = std::max(res, s);
            }

            const auto p = i - k + 1;

            if (cnt[nums[p]]-- == 1)
            {
                cnt.erase(nums[p]);
            }

            s -= nums[p];
        }

        return res;
    }
};