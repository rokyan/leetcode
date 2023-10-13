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
        auto max_so_far = -1;

        for (auto i = 1, j = 0; i < std::size(properties); i++)
        {
            while (j < i && properties[j][0] > properties[i][0])
            {
                max_so_far = std::max(max_so_far, properties[j][1]);
                j++;
            }

            if (max_so_far > properties[i][1])
            {
                res++;
            }
        }

        return res;
    }
};