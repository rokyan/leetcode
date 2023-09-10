// https://leetcode.com/problems/arithmetic-subarrays/description/

class Solution
{
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r)
    {
        std::vector<int> cnums(std::size(nums));
        
        const auto m = std::size(l);
        
        std::vector<bool> res(m, true);
        
        for (auto q = 0; q < m; q++)
        {
            const auto cnt = r[q] - l[q] + 1;
            
            if (cnt <= 2)
            {
                continue;
            }
            
            std::copy(std::begin(nums) + l[q], std::begin(nums) + r[q] + 1, std::begin(cnums));
            
            std::sort(std::begin(cnums), std::begin(cnums) + cnt);
             
            const auto diff = cnums[1] - cnums[0];
            
            for (auto i = 2; i < cnt; i++)
            {
                if (cnums[i] - cnums[i - 1] != diff)
                {
                    res[q] = false;
                    break;
                }
            }
        }
        
        return res;
    }
};