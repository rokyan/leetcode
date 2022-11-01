// https://leetcode.com/problems/3sum/

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        std::vector<std::vector<int>> results;
        
        for (std::size_t i = 0; i + 2 < std::size(nums); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            const auto target = -nums[i];
            
            std::size_t j = i + 1;
            std::size_t k = std::size(nums) - 1;
            
            while (j < k)
            {
                if (nums[j] + nums[k] < target)
                {
                    j++;
                }
                else if (nums[j] + nums[k] > target)
                {
                    k--;
                }
                else
                {
                    results.push_back({ nums[i], nums[j], nums[k] });
                    
                    j++;
                    k--;
                    
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }
        
        return results;
    }
};