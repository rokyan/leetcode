// https://leetcode.com/problems/3sum-closest/

class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        auto answer = nums[0] + nums[1] + nums[2];
        
        for (std::size_t i = 0; i + 2 < std::size(nums); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            std::size_t j = i + 1;
            std::size_t k = std::size(nums) - 1;
            
            while (j < k)
            {
                const auto sum = nums[i] + nums[j] + nums[k];
                
                if (std::abs(target - sum) < std::abs(target - answer))
                {
                    answer = sum;
                }
                
                if (sum < target)
                {
                    j++;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
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
        
        return answer;
    }
};