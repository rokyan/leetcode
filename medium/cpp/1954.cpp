// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/

class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        long long n = 1;
        
        while (2 * n * (n + 1) * (2 * n + 1) < neededApples) n++;
        
        return 8 * n;
    }
};