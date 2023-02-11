// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/

class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        long long res = 0;

        for (auto i = 0; i * cost1 <= total; i++)
        {
            const auto rem = total - i * cost1;
            const auto times = rem / cost2;

            res += times + 1;
        }

        return res;
    }
};