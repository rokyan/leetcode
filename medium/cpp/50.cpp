// https://leetcode.com/problems/powx-n/

class Solution
{
public:
    double myPow(double x, int n)
    {       
        bool negative = n < 0;
        
        long long pow = negative ? - (long long) n : n;
        
        double res = 1.0;
        
        while (pow > 0)
        {
            if (pow & 1)
            {
                res *= x;
                pow--;
            }
            else
            {
                x *= x;
                pow >>= 1;
            }
        }
        
        return negative ? 1.0 / res : res;
    }
};