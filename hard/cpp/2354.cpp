// https://leetcode.com/problems/number-of-excellent-pairs/description/

class Solution
{
public:
    long long countExcellentPairs(std::vector<int>& nums, int k)
    {
        std::sort(std::begin(nums), std::end(nums));
        const auto last = std::unique(std::begin(nums), std::end(nums));
        nums.erase(last, std::end(nums));

        std::unordered_map<int, int> cnt;
        auto res = 0LL;

        for (auto num : nums)
        {
            auto bitc = 0;

            while (num > 0)
            {
                bitc += num & 1;
                num >>= 1;
            }

            if ((bitc << 1) >= k)
            {
                res++;
            }

            for (auto c = std::max(0, k - bitc); c <= 32; c++)
            {
                if (const auto it = cnt.find(c); it != std::end(cnt))
                {
                    res += it->second << 1;
                }
            }

            cnt[bitc]++;
        }

        return res;
    }
};