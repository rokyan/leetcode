// https://leetcode.com/problems/sum-of-increasing-product-blocks/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'000 + 7;

public:
    int sumOfBlocks(int n)
    {
        int sum = 1;
        int prev = 1;

        for (int i = 2; i <= n; i++)
        {
            int cur = 1;

            for (int times = 1; times <= i; times++)
            {
                cur = 1LL * cur * (++prev) % mod;
            }

            sum = (0LL + sum + cur) % mod;
        }

        return sum;
    }
};