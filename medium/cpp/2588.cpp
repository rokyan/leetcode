// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

class Solution
{
public:
    long long beautifulSubarrays(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, int> cnt;
        cnt[0] = 1;

        auto res = 0LL;

        for (auto i = 0, x = 0; i < n; i++)
        {
            x ^= nums[i];

            if (const auto it = cnt.find(x); it != std::end(cnt))
            {
                res += it->second;
            }

            cnt[x]++;
        }

        return res;
    }
};