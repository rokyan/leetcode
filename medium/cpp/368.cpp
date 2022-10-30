// https://leetcode.com/problems/largest-divisible-subset/

class Solution
{
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
    {              
        std::sort(std::begin(nums), std::end(nums));
        
        std::vector<int> dp(std::size(nums));
        
        for (int i = 0; i < std::size(nums); i++)
        {
            dp[i] = 1;
            
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        
        auto pos = std::distance(std::begin(dp), std::max_element(std::begin(dp), std::end(dp)));
        
        std::vector<int> answer { nums[pos] };
        
        for (int i = std::size(nums) - 1; i >= 0; i--)
        {
            if (dp[i] + 1 == dp[pos] && nums[pos] % nums[i] == 0)
            {
                pos = i;
                answer.push_back(nums[pos]);
            }
        }
                
        return answer;
    }
};