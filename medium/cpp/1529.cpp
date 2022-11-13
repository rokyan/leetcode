// https://leetcode.com/problems/minimum-suffix-flips/

class Solution
{
public:
    int minFlips(std::string target)
    {
        int result = 0;
        char bit = '0';
        
        for (std::size_t pos = 0; pos < std::size(target); pos++)
        {
            if (target[pos] != bit)
            {
                result++;
                
                if (bit == '0')
                {
                    bit = '1';
                }
                else
                {
                    bit = '0';
                }
            }
        }
        
        return result;
    }
};