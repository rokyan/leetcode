// https://leetcode.com/problems/delete-and-earn/

class Solution
{
public:
    int deleteAndEarn(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        std::vector<std::vector<int>> nums_with_cnts;
        nums_with_cnts.reserve(std::size(nums));
        
        int cnt = 1;
        
        for (std::size_t pos = 1; pos < std::size(nums); pos++)
        {
            if (nums[pos] == nums[pos - 1])
            {
                cnt++;
            }
            else
            {
                nums_with_cnts.push_back({ nums[pos - 1], cnt });
                cnt = 1;
            }
        }
        
        nums_with_cnts.push_back({ nums.back(), cnt });
        
        int taken = nums_with_cnts[0][0] * nums_with_cnts[0][1];
        int skipped = 0;
        
        for (std::size_t pos = 1; pos < std::size(nums_with_cnts); pos++)
        {
            if (nums_with_cnts[pos][0] == nums_with_cnts[pos - 1][0] + 1)
            {
                const int last_taken = taken;
                
                taken = nums_with_cnts[pos][0] * nums_with_cnts[pos][1] + skipped;
                skipped = std::max(skipped, last_taken);
            }
            else
            {
                const int last_taken = taken;
                
                taken = nums_with_cnts[pos][0] * nums_with_cnts[pos][1] + std::max(taken, skipped);
                skipped = std::max(skipped, last_taken);
            }
        }
        
        return std::max(taken, skipped);
    }
};