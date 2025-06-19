// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int countPartitions(const std::vector<int>& nums, int k)
    {
        const int n = std::size(nums);

        std::multiset<int> seg;

        std::vector<int> dp(n + 1);
        std::vector<int> ps(n + 1);
        ps[0] = 1;

        for (int lo = 1, hi = 1; hi <= n; hi++)
        {
            seg.insert(nums[hi - 1]);

            while (*std::rbegin(seg) - *std::begin(seg) > k)
            {
                seg.erase(seg.find(nums[lo++ - 1]));
            }

            dp[hi] = lo - 1 == 0 ? ps[hi - 1] : (ps[hi - 1] - ps[lo - 2]);
            dp[hi] = (dp[hi] % mod + mod) % mod;

            ps[hi] = dp[hi];
            ps[hi] += ps[hi - 1];
            ps[hi] %= mod;
        }

        return dp.back();
    }
};