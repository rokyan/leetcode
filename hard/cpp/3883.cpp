// https://leetcode.com/problems/count-non-decreasing-arrays-with-given-digit-sums/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'007;
    static constexpr int maxVal = 5000;

public:
    int countArrays(const std::vector<int>& digitSum)
    {
        std::vector<int> dp(maxVal + 1);
        std::vector<int> prec(maxVal + 1);

        for (int x = 0; x <= maxVal; x++)
        {
            prec[x] = calcSum(x);
        }

        for (int x = 0; x <= maxVal; x++)
        {
            const int ds = prec[x];

            if (ds == digitSum[0])
            {
                dp[x] = 1;
            }
        }

        for (int i = 1; i < digitSum.size(); i++)
        {
            const int s = digitSum[i];
            int acc = 0;

            for (int x = 0; x <= maxVal; x++)
            {
                acc = (acc + dp[x]) % mod;

                const int ds = prec[x];

                if (ds == digitSum[i])
                {
                    dp[x] = acc;
                }
                else
                {
                    dp[x] = 0;
                }
            }
        }

        int res = 0;

        for (int x = 0; x <= maxVal; x++)
        {
            res = (res + dp[x]) % mod;
        }

        return res;
    }

private:
    static int calcSum(int x)
    {
        int sum = 0;

        while (x)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
};