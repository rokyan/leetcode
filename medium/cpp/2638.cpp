// https://leetcode.com/problems/count-the-number-of-k-free-subsets/description/

class Solution
{
public:
    long long countTheNumOfKFreeSubsets(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> tail;

        std::sort(std::begin(nums), std::end(nums));
        auto n = 1;

        for (auto num : nums)
        {
            if (auto it = tail.find(num - k); it != std::end(tail))
            {
                const auto old = it->second;
                tail.erase(it);
                tail.emplace(num, old + 1);
                n = std::max(n, old + 1);
            }
            else
            {
                tail.emplace(num, 1);
            }
        }

        std::vector<long long> dp(n + 2);
        dp[0] = 1;
        dp[1] = 1;

        for (auto i = 2; i <= n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        auto res = 1LL;

        for (const auto& [val, cnt] : tail)
        {
            res *= dp[cnt + 1];
        }

        return res;
    }
};