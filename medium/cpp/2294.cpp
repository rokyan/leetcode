// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

class Solution
{
public:
    int partitionArray(std::vector<int>& nums, int k)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        int ans = 1;
        int prev = 0;
        
        for (int i = 1; i < std::size(nums); i++)
        {
            if (nums[i] - nums[prev] > k)
            {
                prev = i;
                ans++;
            }
        }
        
        return ans;
    }
};