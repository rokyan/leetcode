// https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/

class Solution
{
public:
    int squareFreeSubsets(std::vector<int>& nums)
    {
        constexpr auto n = 10;
        constexpr auto mod = 1000'000'000 + 7;

        std::array<int, n> primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

        std::vector<int> dp(1 << n);

        auto ones = 0;

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (nums[i] == 1)
            {
                ones++;
                continue;
            }

            auto mask = 0;

            for (auto j = 0; j < n; j++)
            {
                auto cnt = 0;

                while (nums[i] % primes[j] == 0)
                {
                    nums[i] /= primes[j];
                    cnt++;
                }

                if (cnt > 1)
                {
                    mask = -1;
                    break;
                }

                if (cnt == 1)
                {
                    mask |= 1 << j;
                }
            }

            if (mask == -1)
            {
                continue;
            }

            std::vector<int> dpn(dp);
            dpn[mask]++;

            for (auto m = 0; m < (1 << n); m++)
            {
                if ((m & mask) == 0)
                {
                    dpn[m | mask] += dp[m];
                    dpn[m | mask] %= mod;
                }
            }

            dp = std::move(dpn);
        }

        auto ones_sub = 1;

        for (auto _ = 0; _ < ones; _++)
        {
            ones_sub *= 2;
            ones_sub %= mod;
        }

        auto res = 0LL;

        for (auto m = 1; m < (1 << n); m++)
        {
            res += dp[m];
            res %= mod;
        }

        res *= ones_sub;
        res %= mod;

        res += ones_sub - 1;
        res %= mod;

        return res;
    }
};