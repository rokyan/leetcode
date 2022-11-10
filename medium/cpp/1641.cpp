// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution
{
public:
    int countVowelStrings(int n)
    {
        int dp[5] = { 1, 1, 1, 1, 1 };
        
        for (int nn = 2; nn <= n; nn++)
        {
            int dp2[5] = { 0 };
            
            for (int i = 0; i < 5; i++)
            {
                for (int j = i; j < 5; j++)
                {
                    dp2[j] += dp[i];
                }
            }
            
            for (int i = 0; i < 5; i++)
            {
                dp[i] = dp2[i];
            }
        }
        
        return std::accumulate(std::begin(dp), std::end(dp), 0);
    }
};