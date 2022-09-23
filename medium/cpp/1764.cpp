// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/

class Solution
{
public:
    bool canChoose(std::vector<std::vector<int>>& groups, std::vector<int>& nums)
    {
        int group_idx = 0;
        int last = -1;
        
        for (int i = 0; i < std::size(nums); i++)
        {
            int j = i;
            int elem_idx = std::size(groups[group_idx]) - 1;
            
            while (j > last && elem_idx >= 0 && groups[group_idx][elem_idx] == nums[j])
            {
                j--;
                elem_idx--;
            }
            
            if (elem_idx == -1)
            {
                group_idx++;
                last = i;
            }
            
            if (group_idx == std::size(groups))
            {
                return true;
            }
        }
        
        return false;
    }
};