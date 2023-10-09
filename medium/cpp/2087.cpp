// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/

class Solution
{
public:
    int minCost(std::vector<int>& startPos, std::vector<int>& homePos, std::vector<int>& rowCosts, std::vector<int>& colCosts)
    {
        auto res = 0;

        auto x = startPos[0];
        auto y = homePos[0];

        if (x < y)
        {
            for (auto i = x + 1; i <= y; i++)
            {
                res += rowCosts[i];
            }
        }
        else if (y < x)
        {
            for (auto i = x - 1; i >= y; i--)
            {
                res += rowCosts[i];
            }
        }

        x = startPos[1];
        y = homePos[1];

        if (x < y)
        {
            for (auto i = x + 1; i <= y; i++)
            {
                res += colCosts[i];
            }
        }
        else if (y < x)
        {
            for (auto i = x - 1; i >= y; i--)
            {
                res += colCosts[i];
            }
        }

        return res;
    }
};