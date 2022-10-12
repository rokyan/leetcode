// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution
{
public:
    int largestCombination(vector<int>& candidates)
    {
        int ans = 0;
        
        for (int bit = 0; bit < 32; bit++)
        {
            int cnt = 0;
            
            for (std::size_t pos = 0; pos < std::size(candidates); pos++)
            {
                if ((1 << bit) & candidates[pos])
                {
                    cnt++;
                }
            }
            
            ans = std::max(ans, cnt);
        }
        
        return ans;
    }
};