// https://leetcode.com/problems/maximum-compatibility-score-sum/

class Solution
{
public:
    int maxCompatibilitySum(std::vector<std::vector<int>>& students, std::vector<std::vector<int>>& mentors)
    {
        const auto n = std::size(students);
        
        std::vector<int> idx(n);
        
        for (auto i = 0; i < n; i++)
        {
            idx[i] = i;
        }
        
        auto ans = 0;
        
        do
        {
            auto sum = 0;
            
            for (auto i = 0; i < n; i++)
            {
                for (auto j = 0; j < std::size(students[idx[i]]); j++)
                {
                    if (students[idx[i]][j] == mentors[i][j])
                    {
                        sum++;
                    }
                }
            }
            
            ans = std::max(ans, sum);
        }
        while (std::next_permutation(std::begin(idx), std::end(idx)));
        
        return ans;
    }
};