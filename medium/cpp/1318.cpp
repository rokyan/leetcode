// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int answer = 0;
        
        while (a > 0 || b > 0 || c > 0)
        {
            auto a_d = a & 1;
            auto b_d = b & 1;
            auto c_d = c & 1;
            
            if (c_d == 1)
            {
                answer += a_d == 0 && b_d == 0;
            }
            else
            {
                answer += a_d == 1;
                answer += b_d == 1;
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
};