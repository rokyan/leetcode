// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution
{
public:
    int maximumSum(vector<int>& nums)
    {
        auto dsum = [](auto num)
        {
            auto sum = 0;
            
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            
            return sum;
        };
        
        int max_val[100] = { 0 };
        
        int ans = -1;
        
        for (auto num : nums)
        {
            const auto s = dsum(num);
            
            if (max_val[s] > 0)
            {
                ans = std::max(ans, max_val[s] + num);
            }
            
            max_val[s] = std::max(max_val[s], num);
        }
        
        return ans;
    }
};