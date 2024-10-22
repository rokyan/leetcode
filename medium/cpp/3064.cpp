// https://leetcode.com/problems/guess-the-number-using-bitwise-questions-i/description/

/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution
{
public:
    int findNumber()
    {
        auto res = 0;

        for (auto bit = 0; bit < 31; bit++)
        {
            if (commonSetBits(1 << bit))
            {
                res |= (1 << bit);
            }
        }

        return res;
    }
};