// https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution
{
public:
    int maxChunksToSorted(std::vector<int>& arr)
    {
        int ans = 0;
        int max_val = 0;
        
        for (int i = 0; i < std::size(arr); i++)
        {
            max_val = std::max(max_val, arr[i]);
            
            if (i == max_val)
            {
                ans++;
            }
        }
        
        return ans;
    }
};