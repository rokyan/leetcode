// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution
{
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k)
    {
        std::vector<int> dp(std::size(arr));
        
        for (int i = 0; i < std::size(arr); i++)
        {
            int cur_max = 0;
            int cur_sum = 0;
            
            for (int j = i, kk = k; j >= 0 && kk > 0; j--, kk--)
            {
                cur_max = std::max(cur_max, arr[j]);
                cur_sum = (i - j + 1) * cur_max;
                
                dp[i] = std::max(dp[i], cur_sum + (j > 0 ? dp[j - 1] : 0));
            }
        }
        
        return dp.back();
    }
};