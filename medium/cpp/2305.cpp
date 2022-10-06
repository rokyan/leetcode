class Solution
{
public:
    int distributeCookies(std::vector<int>& cookies, int k)
    {
        const auto n = std::size(cookies);        
        
        std::vector<int> sum(1 << n);
        
        for(int mask = 0; mask < (1 << n); mask++)
        {
            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    sum[mask] += cookies[i];
                }
            }
        }
        
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(1 << n, 1001 * 1001));

        dp[0][0] = 0;
        
        for(int i = 1; i <= k; i++)
        {
            for(int mask = 0; mask < (1 << n); mask++)
            {
                for (int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask)
                {
                    dp[i][mask] = std::min(dp[i][mask], std::max(sum[sub_mask], dp[i - 1][mask ^ sub_mask]));
                }
            }
        }

        return dp[k][(1 << n) - 1];
    }
};