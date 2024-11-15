// https://leetcode.com/problems/find-the-maximum-factor-score-of-array/description/

class Solution
{
public:
    long long maxScore(const std::vector<int>& nums)
    {
        auto res = 0LL;

        for (auto i = 0; i <= std::size(nums); i++)
        {
            auto gcd_val = 0LL;
            auto lcm_val = 1LL;

            for (auto j = 0; j < std::size(nums); j++)
            {
                if (j != i)
                {
                    gcd_val = gcd(gcd_val, nums[j]);
                    lcm_val = lcm(lcm_val, nums[j]);
                }
            }

            res = std::max(res, gcd_val * lcm_val);
        }

        return res;
    }

private:
    long long gcd(long long x, long long y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }

    long long lcm(long long x, long long y)
    {
        return x * y / gcd(x, y);
    }
};