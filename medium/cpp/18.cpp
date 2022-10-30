// https://leetcode.com/problems/4sum/

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> answer;
        
        std::sort(std::begin(nums), std::end(nums));
        
        for (std::size_t i = 0; i + 3 < std::size(nums); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            for (std::size_t j = i + 1; j < std::size(nums); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                
                std::size_t k = j + 1;
                std::size_t l = std::size(nums) - 1;
                
                const auto updated_target = target - nums[i] - nums[j];
                
                while (k < l)
                {
                    if (nums[k] + nums[l] < updated_target)
                    {
                        k++;
                    }
                    else if (nums[k] + nums[l] > updated_target)
                    {
                        l--;
                    }
                    else
                    {
                        answer.push_back({ nums[i], nums[j], nums[k], nums[l] });
                        
                        k++;
                        l--;
                        
                        while (k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                        
                        while (k < l && nums[l] == nums[l + 1])
                        {
                            l--;
                        }
                    }
                }
            }
        }
        
        return answer;
    }
};