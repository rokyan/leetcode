// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution
{
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums)
    {
        const auto nums_count = std::size(nums);
        std::vector<int> buffer(nums_count);
        
        std::size_t buffer_pt = 0;
        
        for (std::size_t pos = 0; pos < nums_count; pos++)
        {
            if (nums[pos] > 0)
            {
                buffer[2 * buffer_pt++] = nums[pos];
            }
        }
        
        buffer_pt = 0;
        
        for (std::size_t pos = 0; pos < nums_count; pos++)
        {
            if (nums[pos] < 0)
            {
                buffer[2 * (buffer_pt++) + 1] = nums[pos];
            }
        }
       
        return buffer;
    }
};