// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int>& nums)
    {
        for (auto e : nums)
        {
            const auto idx = std::abs(e) - 1;
            nums[idx] *= -1;
        }
       
        std::vector<int> answer;
        answer.reserve(nums.size());
        
        for (auto e : nums)
        {
            const auto idx = std::abs(e) - 1;
            
            if (nums[idx] > 0)
            {
                answer.push_back(std::abs(e));
                nums[idx] *= -1;
            }
        }
        
        return answer;
    }
};