// https://leetcode.com/problems/count-total-number-of-colored-cells/description/

class Solution
{
public:
    long long coloredCells(int n)
    {
        const auto side = 2 * (n - 1) + 1;

        return 1LL * side * side - 2LL * n * (n - 1);    
    }
};