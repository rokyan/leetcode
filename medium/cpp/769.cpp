// https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution
{
public:
    int maxChunksToSorted(std::vector<int>& arr)
    {
        const auto n = std::size(arr);
        
        std::vector<int> max_on_pref(n);
        max_on_pref[0] = arr[0];
        
        for (std::size_t i = 1; i < n; i++)
        {
            max_on_pref[i] = std::max(max_on_pref[i - 1], arr[i]);
        }
        
        auto ans = 0;
        
        for (std::size_t i = 0; i < n; i++)
        {
            if (max_on_pref[i] == i)
            {
                ans++;
            }
        }
        
        return ans;
    }
};