// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution
{
private:
    static constexpr int MOD = 1000 * 1000 * 1000 + 7;
    
public:
    int concatenatedBinary(int n)
    {       
        std::vector<int> bd(20);
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++)
        {
            int m = 0;            
            int num = i;
            
            while (num > 0)
            {
                bd[m++] = num % 2;
                num /= 2;
            }
            
            while (m > 0)
            {
                ans = 2 * ans + bd[--m];
                ans %= MOD;
            }
        }
        
        return ans;
    }
};