// https://leetcode.com/problems/sort-threats-by-severity-and-exploitability/description/

class Solution
{
public:
    std::vector<std::vector<int>> sortThreats(std::vector<std::vector<int>>& threats)
    {
        std::ranges::sort(threats, [](const auto& lhs, const auto& rhs) {
            const auto lscore = 2LL * lhs[1] + lhs[2];
            const auto rscore = 2LL * rhs[1] + rhs[2];
            return lscore > rscore || lscore == rscore && lhs[0] < rhs[0];
        });

        return threats;
    }
};