// https://leetcode.com/problems/count-of-interesting-subarrays/description/

class Solution
{
public:
    long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, int> cnt;
        cnt[0] = 1;

        auto res = 0LL;

        for (auto i = 0, pre = 0; i < n; i++)
        {
            pre += nums[i] % modulo == k;
            pre %= modulo;

            const auto val = (pre - k + modulo) % modulo;

            if (auto it = cnt.find(val); it != std::end(cnt))
            {
                res += it->second;
            }

            cnt[pre]++;
        }

        return res;
    }
};