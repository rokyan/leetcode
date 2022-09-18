// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution
{
public:
    int maxTurbulenceSize(std::vector<int>& arr)
    {
        const int n = std::size(arr);
        
        if (n == 1)
        {
            return 1;
        }
        
        int pos = 0;
        int ans = 1;
        
        while (pos + 1 < n)
        {            
            if (arr[pos] != arr[pos + 1])
            {
                bool more = arr[pos] < arr[pos + 1];
                int start = pos;
                
                while (pos + 1 < n)
                {
                    if (more)
                    {
                        if (arr[pos] < arr[pos + 1]) pos++; else break;
                    }
                    else
                    {
                        if (arr[pos] > arr[pos + 1]) pos++; else break;
                    }
                    
                    more ^= true;
                }
                
                ans = std::max(ans, pos - start + 1);
            }
            else
            {
                pos++;
            }
        }
        
        return ans;
    }
};