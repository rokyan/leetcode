// https://leetcode.com/problems/single-number-iii/

class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int>& nums)
    {
        int bit = 0;
        
        while (bit < 32)
        {
            int count = 0;
            
            for (std::size_t pos = 0; pos < std::size(nums); pos++)
            {
                if ((1 << bit) & nums[pos])
                {
                    count++;
                }
            }
            
            if (count & 1)
            {
                break;
            }
            
            bit++;
        }
        
        int first = 0;
        int second = 0;
        
        for (std::size_t pos = 0; pos < std::size(nums); pos++)
        {
            if ((1 << bit) & nums[pos])
            {
                first ^= nums[pos];
            }
            else
            {
                second ^= nums[pos];
            }
        }
        
        return { first, second };
    }
};