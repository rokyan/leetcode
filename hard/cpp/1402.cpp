// https://leetcode.com/problems/reducing-dishes/description/

class Solution
{
public:
    int maxSatisfaction(std::vector<int>& satisfaction)
    {
        std::sort(std::begin(satisfaction), std::end(satisfaction));
        
        int ans = 0;
        
        for (std::size_t start {}; start < std::size(satisfaction); start++)
        {
            int sum = 0;
            
            for (std::size_t pos = start; pos < std::size(satisfaction); pos++)
            {
                sum += satisfaction[pos] * (pos - start + 1);
            }
            
            ans = std::max(ans, sum);
        }
        
        return ans;
    }
};