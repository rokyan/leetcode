// https://leetcode.com/problems/maximum-subarray/description/

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        auto sum = 0;
        auto ans = std::numeric_limits<int>::min();
        
        for (auto e : nums)
        {
            const auto subSum = std::max(e, sum + e);
            ans = std::max(ans, subSum);
            sum = subSum;
        }
        
        return ans;
    }
};  