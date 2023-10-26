// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/

class Solution
{
public:
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        std::unordered_map<long long, int> pref;
        pref[0] = -1;
        auto res = 0;
        auto sum = 0LL;

        for (auto i = 0; i < std::size(nums); i++)
        {
            sum += nums[i];
            const auto rem = sum - k;

            if (const auto it = pref.find(rem); it != std::end(pref))
            {
                res = std::max(res, i - it->second);
            }

            if (const auto it = pref.find(sum); it == std::end(pref))
            {
                pref.insert({ sum, i });
            }
        }

        return res;
    }
};