// https://leetcode.com/problems/perfect-squares/description/

class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> squares;
        
        for (auto i = 1; i * i <= n; ++i)
        {
            squares.push_back(i * i);
        }
        
        std::vector<int> dp(n + 1, n);

        dp[0] = 0;
        
        for (auto i = 1; i <= n; ++i)
        {
            for (auto e : squares)
            {
                if (e > i)
                {
                    break;
                }
                
                dp[i] = std::min(dp[i], dp[i - e] + 1);
            }
        }
        
        return dp[n];
    }
};