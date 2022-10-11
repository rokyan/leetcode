// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution
{
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs)
    {
        const auto n = std::size(days);
        
        std::vector<int> dp(n + 1);
        
        for (int i = 1; i <= n; i++)
        {
            dp[i] = costs[0] + dp[i - 1];
            
            int j = i;
            
            while (j > 0 && days[i - 1] - days[j - 1] + 1 <= 30)
            {
                if (days[i - 1] - days[j - 1] + 1 <= 7)
                {
                    dp[i] = std::min(dp[i], dp[j - 1] + costs[1]);
                }
                
                if (days[i - 1] - days[j - 1] + 1 <= 30)
                {
                    dp[i] = std::min(dp[i], dp[j - 1] + costs[2]);
                }
                
                j--;
            }
        }
        
        return dp.back();
    }
};