// https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int count = 0;
        
        while (left < right)
        {
            count++;
            
            left >>= 1;
            right >>= 1;
        }
        
        return left << count;
    }
};