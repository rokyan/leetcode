// https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-i/description/

class Solution
{
public:
    int minCost(int m, int n)
    {
        if (m == 1 && n == 1)
        {
            return 1;
        }

        if (m == 1 && n == 2 || m == 2 && n == 1)
        {
            return 3;
        }

        return -1;
    }
};