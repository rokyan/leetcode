// https://leetcode.com/problems/2-keys-keyboard/

class Solution
{
public:
    int minSteps(int n)
    {
        std::vector<int> dp(n + 1);        
        dp[1] = 0;
        
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i;
            
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    dp[i] = std::min(dp[i], dp[i / j] + j);
                }
            }
        }
        
        return dp.back();
    }
};