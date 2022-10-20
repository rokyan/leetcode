// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution
{
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
    {
        auto sum = 0;
        
        for (std::size_t i = 0; i < std::size(nums); i++)
        {
            if (nums[i] % 2 == 0)
            {
                sum += nums[i];
            }
        }
        
        std::vector<int> answer;
        answer.reserve(std::size(queries));
        
        for (const auto& q : queries)
        {
            const auto val = q[0];
            const auto pos = q[1];
            
            auto& num = nums[pos];
            
            const auto n_val = num + val;
            
            if (std::abs(num) % 2 == 0 && std::abs(n_val) % 2 == 0)
            {
                sum += val;
            }
            
            if (std::abs(num) % 2 == 0 && std::abs(n_val) % 2 == 1)
            {
                sum -= num;
            }
            
            if (std::abs(num) % 2 == 1 && std::abs(n_val) % 2 == 0)
            {
                sum += n_val;
            }
            
            num = n_val;
            
            answer.push_back(sum);
        }
        
        return answer;
    }
};