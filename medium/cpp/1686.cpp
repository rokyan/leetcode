// https://leetcode.com/problems/stone-game-vi/description/

class Solution
{
public:
    int stoneGameVI(std::vector<int>& aliceValues, std::vector<int>& bobValues)
    {
        const auto n = std::size(aliceValues);

        std::vector<std::pair<int, int>> p(n);

        for (auto i = 0; i < n; i++)
        {
            p[i] = { aliceValues[i], bobValues[i] };
        }

        std::sort(std::begin(p), std::end(p), [](const auto& lhs, const auto& rhs) {
            return lhs.first + lhs.second > rhs.first + rhs.second;
        });

        auto atot = 0;
        auto btot = 0;

        for (auto i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                atot += p[i].first;
            }
            else
            {
                btot += p[i].second;
            }
        }

        return atot > btot
            ? 1
            : (atot == btot) ? 0 : -1;
    }
};