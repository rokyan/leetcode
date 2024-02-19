// https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution
{
public:
    int minSubarray(std::vector<int>& nums, int p)
    {
        const auto sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0LL);

        if (sum % p == 0)
        {
            return 0;
        }

        std::unordered_map<int, int> pref{ { 0, -1 } };

        auto mod = sum % p;
        auto rsum = 0;
        auto res = -1;

        for (auto i = 0; i < std::size(nums); i++)
        {
            rsum += nums[i];
            rsum %= p;

            const auto req = (rsum - mod + p) % p;

            if (const auto it = pref.find(req); it != std::cend(pref))
            {
                res = res == -1 ? i - it->second : std::min(res, i - it->second);
            }

            pref[rsum] = i;
        }

        return res == std::size(nums) ? -1 : res;
    }
};