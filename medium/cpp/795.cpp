// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution
{
public:
    int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right)
    {
        return count(nums, right + 1) - count(nums, left);
    }
    
private:
    long long count(const std::vector<int>& nums, int right)
    {
        const int n = std::size(nums);
        
        int last = -1;
        long long ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= right)
            {
                if (last != -1)
                {
                    const int len = i - last;
                    
                    ans += 1LL * len * (len + 1) / 2;
                }
                
                last = -1;
            }
            else
            {
                if (last == -1)
                {
                    last = i;
                }
            }
        }
        
        if (last != -1)
        {
            const int len = n - last;
            
            ans += 1LL * len * (len + 1) / 2;
        }
        
        return ans;
    }
};