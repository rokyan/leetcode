// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/

class Solution
{
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties)
    {
        std::sort(std::begin(properties), std::end(properties), [](const auto& lhs, const auto& rhs) {
            return lhs[0] > rhs[0] || lhs[0] == rhs[0] && lhs[1] > rhs[1];
        });

        auto res = 0;

        std::set<int, greater<int>> s;

        for (auto i = 1, j = 0; i < std::size(properties); i++)
        {
            while (j < i && properties[j][0] > properties[i][0])
            {
                s.insert(properties[j][1]);
                j++;
            }

            if (*std::begin(s) > properties[i][1])
            {
                res++;
            }
        }

        return res;
    }
};