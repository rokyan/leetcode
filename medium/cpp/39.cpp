class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::vector<int> solution;
        std::vector<std::vector<int>> solutions;

        std::sort(std::begin(candidates), std::end(candidates));       

        solve(0, target, candidates, solution, solutions);

        return solutions;
    }

private:    
    void solve(int pos, int target, const std::vector<int>& candidates,
        std::vector<int>& solution, std::vector<std::vector<int>>& solutions)
    {
        if (target < 0)
        {
            return;
        }

        if (target == 0)
        {
            solutions.push_back(solution);
            return;
        }  
        
        for (auto i = pos; i < std::size(candidates) && candidates[pos] <= target; i++)
        {
            solution.push_back(candidates[i]);
            solve(i, target - candidates[i], candidates, solution, solutions);
            solution.pop_back();
        }
    }
};