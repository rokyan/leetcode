// https://leetcode.com/problems/permutations-ii/

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        
        std::vector<std::vector<int>> res;
        
        std::vector<int> acc;
        acc.reserve(std::size(nums));
        
        std::vector<int> used;
        used.resize(std::size(nums));
        
        generate(nums, acc, used, res);
        
        return res;
    }
    
private:
    void generate(const std::vector<int>& nums, std::vector<int>& acc, std::vector<int>& used, std::vector<std::vector<int>>& res)
    {
        if (std::size(acc) == std::size(nums))
        {
            res.push_back(acc);
            return;
        }
        
        for (std::size_t i = 0; i < std::size(nums); i++)
        {
            if (!used[i] && (i == 0 || nums[i] != nums[i - 1] || used[i - 1]))
            {
                used[i] = true;
                acc.push_back(nums[i]);
                generate(nums, acc, used, res);
                used[i] = false;
                acc.pop_back();
            }
        }
    }
};