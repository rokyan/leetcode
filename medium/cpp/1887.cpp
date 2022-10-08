// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

class Solution
{
public:
    int reductionOperations(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        int acc = 0;
        int tot = 0;
        
        for (std::size_t i = 1; i < std::size(nums); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                acc++;                
            }

            tot += acc;
        }
        
        return tot;
    }
};