// https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/

class Solution
{
public:
    int minimumAddedCoins(std::vector<int>& coins, int target)
    {
        std::ranges::sort(coins);

        auto res = 0;
        auto upper = 0;

        for (auto coin : coins)
        {
            if (coin <= upper)
            {
                upper += coin;
            }
            else
            {
                while (upper + 1 < coin)
                {
                    res++;
                    upper = 2 * upper + 1;
                }

                upper += coin;
            }

            if (upper >= target)
            {
                break;
            }
        }

        while (upper < target)
        {
            res++;
            upper = 2 * upper + 1;
        }

        return res;
    }
};