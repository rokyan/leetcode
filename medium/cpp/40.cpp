// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::sort(std::begin(candidates), std::end(candidates));
        
        std::vector<std::vector<int>> solution;
        
        solve(candidates, target, solution);
        
        return solution;
    }
    
private:
    void solve(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& solution,
        std::size_t pos = 0, std::vector<int> acc = {}, int acc_sum = 0)
    {
        if (acc_sum == target)
        {
            solution.push_back(acc);
            return;
        }
        
        for (std::size_t next_pos = pos; next_pos < std::size(candidates); next_pos++)
        {
            if (candidates[next_pos] + acc_sum > target)
            {
                break;
            }
            
            if (next_pos == pos || candidates[next_pos] != candidates[next_pos - 1])
            {
                acc.push_back(candidates[next_pos]);
                solve(candidates, target, solution, next_pos + 1, acc, acc_sum + candidates[next_pos]);
                acc.pop_back();
            }
        }
        
    }
};