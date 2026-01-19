// https://leetcode.com/problems/number-of-alternating-xor-partitions/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'007;

public:
    int alternatingXOR(const std::vector<int>& nums, int target1, int target2)
    {
        const int n = nums.size();

        std::array<int, 2> targets{target1, target2};

        std::vector<std::unordered_map<int, int>> dp(2);
        dp[1][0] = 1;

        int x = 0;
        int last = 0;

        for (int i = 0; i < n; i++)
        {
            x ^= nums[i];

            auto ndp{dp};
 
            for (int j = 0; j < 2; j++)
            {
                const int r = x ^ targets[j];

                if (const auto it = dp[j ^ 1].find(r); it != dp[j ^ 1].end())
                {
                    ndp[j][x] += it->second;
                    ndp[j][x] %= mod;
                }
            }

            if (i == n - 1)
            {
                last = (dp[0][x] + dp[1][x]) % mod;
            }

            dp = std::move(ndp);
        }

        return ((dp[0][x] + dp[1][x] - last) % mod + mod) % mod;
    }
};