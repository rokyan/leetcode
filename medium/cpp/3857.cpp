// https://leetcode.com/problems/minimum-cost-to-split-into-ones/description/

class Solution
{
public:
    int minCost(int n)
    {
        return n * (n - 1) / 2;
    }
};