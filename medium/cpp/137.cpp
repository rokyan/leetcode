// https://leetcode.com/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        int res = 0;
        
        for (auto bit = 0; bit < 32; bit++)
        {
            int count = 0;
            
            for (auto i = 0; i < std::size(nums); i++)
            {
                if ((1 << bit) & nums[i])
                {
                    count++;
                }
            }
            
            if (count % 3 == 1)
            {
                res += (1 << bit);
            }
        }
        
        return res;
    }
};