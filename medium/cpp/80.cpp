// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        std::size_t next = 0;
        
        for (std::size_t pos = 1; pos < std::size(nums); )
        {
            if (nums[pos] == nums[next])
            {
                if (pos + 1 < std::size(nums) && nums[pos] == nums[pos + 1])
                {
                    pos++;
                }
                else
                {
                    nums[++next] = nums[pos++];
                }
            }
            else
            {
                nums[++next] = nums[pos++];
            }
        }
        
        return next + 1;
    }
};