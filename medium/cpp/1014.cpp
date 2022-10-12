// https://leetcode.com/problems/best-sightseeing-pair/

class Solution
{
public:
    int maxScoreSightseeingPair(std::vector<int>& values)
    {
        const auto n = std::size(values);
        
        auto prev = values[0] + 0;
        auto ans = values[1] - 1 + values[0] + 0;
        
        for (int j = 1; j < n; j++)
        {
            auto cur = values[j] - j;
            
            ans = std::max(ans, prev + cur);            
            prev = std::max(prev, values[j] + j);
        }
        
        return ans;
    }
};