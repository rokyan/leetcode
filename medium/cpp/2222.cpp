// https://leetcode.com/problems/number-of-ways-to-select-buildings/

class Solution
{
public:
    long long numberOfWays(std::string s)
    {
        long long answer = 0;
        
        long long zero = 0;
        long long one = 0;
        
        long long end_with_zero = 0;
        long long end_with_one = 0;
        
        for (char c : s)
        {           
            if (c == '0')
            {
                answer += end_with_one;
                zero++;
                end_with_zero += one;
            }
            else
            {
                answer += end_with_zero;
                one++;
                end_with_one += zero;
            }
        }
        
        return answer;
    }
};