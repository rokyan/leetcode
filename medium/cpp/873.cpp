// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution
{
public:
    int lenLongestFibSubseq(std::vector<int>& arr)
    {
        const auto n = std::size(arr);
        
        std::unordered_set<int> vals(std::begin(arr), std::end(arr));
        
        int ans = 0;

        for (std::size_t i = 0; i + 1 < n; i++)
        {
            for (std::size_t j = i + 1; j < n; j++)
            {
                int prev = arr[i];
                int curr = arr[j];
                
                int len = 2;
                               
                while (true)
                {
                    const int next = prev + curr;
                    const auto it = vals.find(next);
                    
                    if (it == std::end(vals))
                    {
                        break;
                    }
                    
                    len++;
                    
                    prev = curr;
                    curr = next;
                }
                
                if (len > 2)
                {
                    ans = std::max(ans, len);
                }
            }
        }
        
        return ans;
    }
};