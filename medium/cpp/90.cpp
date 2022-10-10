// https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> solutions;
        
        std::sort(std::begin(nums), std::end(nums));
        
        solve(solutions, nums, 0);
        
        return solutions;
    }
    
private:
    void solve(std::vector<std::vector<int>>& solutions, const std::vector<int>& nums, std::size_t pos)
    {
        solutions.push_back(acc);
        
        for (std::size_t n_pos = pos; n_pos < std::size(nums); n_pos++)
        {
            if (n_pos == pos || nums[n_pos] != nums[n_pos - 1])
            {
                acc.push_back(nums[n_pos]);
                solve(solutions, nums, n_pos + 1);
                acc.pop_back();
            }
        }
    }

private:
    std::vector<int> acc;
};