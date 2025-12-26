// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/

class Solution
{
public:
    int totalWaviness(int num1, int num2)
    {
        int res = 0;

        for (int x = num1; x <= num2; x++)
        {
            res += count(x);
        }

        return res;
    }

private:
    int count(int x)
    {
        if (x < 100)
        {
            return 0;
        }
    
        int prev = x % 10;
        x /= 10;

        int total = 0;

        while (x >= 10)
        {
            const int cur = x % 10;
            x /= 10;
            const int next = x % 10;

            if (next > cur && cur < prev)
            {
                total++;
            }
            else if (next < cur && cur > prev)
            {
                total++;
            }

            prev = cur;
        }

        return total;
    }
};