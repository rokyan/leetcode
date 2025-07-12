// https://leetcode.com/problems/calculate-score-after-performing-instructions/description/

class Solution
{
public:
    long long calculateScore(const std::vector<std::string>& instructions, std::vector<int>& values)
    {
        const auto n = std::size(instructions);

        auto score = 0LL;
        std::vector<char> visited(n);
        auto pointer = 0;

        while (pointer >= 0 && pointer < n && !visited[pointer])
        {
            visited[pointer] = true;

            if (instructions[pointer] == "add")
            {
                score += values[pointer++];
            }
            else
            {
                pointer += values[pointer];
            }
        }

        return score;
    }
};