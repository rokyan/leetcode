// https://leetcode.com/problems/contiguous-array/description/

class Solution
{
private:
    static constexpr auto MAX_LEN = 50000 + 1;

public:  
    int findMaxLength(std::vector<int>& nums)
    {
        std::vector<int> table(2 * MAX_LEN + 1, -1);
        table[MAX_LEN] = 0;
        
        auto balance = 0;
        auto answer = 0;
        
        for (auto i = 0; i < std::size(nums); ++i)
        {
            balance += nums[i] == 0 ? 1 : -1;

            const auto idx = balance + MAX_LEN;
            
            if (table[idx] != -1)
            {
                answer = std::max(answer, i + 1 - table[idx]);
            }
            else
            {
                table[idx] = i + 1;
            }
        }
        
        return answer;
    }
};