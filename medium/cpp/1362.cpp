// https://leetcode.com/problems/closest-divisors/

class Solution
{
public:
    std::vector<int> closestDivisors(int num)
    {
        auto num_plus_1_sol = solve(num + 1);
        auto num_plus_2_sol = solve(num + 2);
        
        return num_plus_1_sol[1] - num_plus_1_sol[0] <= num_plus_2_sol[1] - num_plus_2_sol[0]
            ? num_plus_1_sol
            : num_plus_2_sol;
    }
    
private:
    std::vector<int> solve(int num)
    {
        std::vector<int> ans { 1, num };
        
        for (int i = 2; i * i <= num; i++)
        {
            if (num / i * i == num)
            {
                ans[0] = i;
                ans[1] = num / i;
            }
        }
        
        return ans;
    }
};