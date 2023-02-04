// https://leetcode.com/problems/count-number-of-bad-pairs/description/

class Solution
{
public:
    long long countBadPairs(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        long long res = 1LL * n * (n - 1) / 2;

        std::unordered_map<int, int> cnt;

        for (auto i = 0; i < n; i++)
        {
            const auto d = nums[i] - i;

            const auto it = cnt.find(d);

            if (it != std::end(cnt))
            {
                res -= it->second;
                it->second++;
            }
            else
            {
                cnt.insert({ d, 1 });
            }
        }

        return res;
    }
};