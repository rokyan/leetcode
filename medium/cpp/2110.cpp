// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/

class Solution
{
public:
    long long getDescentPeriods(std::vector<int>& prices)
    {
        auto res = 0LL;
        auto cnt = 1;

        for (auto i = 1; i < std::size(prices); i++)
        {
            if (prices[i] == prices[i - 1] - 1)
            {
                cnt++;
            }
            else
            {
                res += 1LL * cnt * (cnt + 1) / 2;
                cnt = 1;
            }
        }

        res += 1LL * cnt * (cnt + 1) / 2;

        return res;
    }
};