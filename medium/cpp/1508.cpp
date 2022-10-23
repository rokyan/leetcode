// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution
{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {       
        std::vector<int> sums(nums);
        
        for (std::size_t pos = 1; pos < n; pos++)
        {
            sums[pos] += sums[pos - 1];
        }
        
        std::vector<int> all;
        all.reserve(n * (n + 1) / 2);
        
        for (std::size_t left = 0; left < n; left++)
        {
            for (std::size_t right = left; right < n; right++)
            {
                int sum = sums[right];
                
                if (left > 0)
                {
                    sum -= sums[left - 1];
                }
                
                all.push_back(sum);
            }
        }
        
        std::nth_element(std::begin(all), std::begin(all) + left - 1, std::end(all));
        std::nth_element(std::begin(all) + left, std::begin(all) + right - 1, std::end(all));
        
        const int mod = 1000000000 + 7;
        
        int ans = 0;
        
        for (std::size_t pos = left; pos <= right; pos++)
        {
            ans += all[pos - 1];
            ans %= mod;
        }
        
        return ans;
    }
};