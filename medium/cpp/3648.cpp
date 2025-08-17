// https://leetcode.com/problems/minimum-sensors-to-cover-grid/description/

class Solution
{
public:
    int minSensors(int n, int m, int k)
    {
        const auto side = 2 * k + 1;
        return ((n + side - 1) / side) * ((m + side - 1) / side); 
    }
};