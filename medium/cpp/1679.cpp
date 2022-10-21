// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution
{
public:
    int maxOperations(std::vector<int>& nums, int k)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        int left = 0;
        int right = std::size(nums) - 1;
        
        int counter = 0;
        
        while (left < right)
        {
            if (nums[left] + nums[right] == k)
            {
                counter++;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] > k)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        return counter;
    }
};