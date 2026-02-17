// https://leetcode.com/problems/total-distance-to-type-a-string-using-one-finger/description/

class Solution
{
public:
    int totalDistance(const std::string& s)
    {
        const std::vector<std::string> keyboard{
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };

        const auto getPos = [&keyboard](char c) -> std::pair<int, int>
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < keyboard[i].size(); j++)
                {
                    if (keyboard[i][j] == c)
                    {
                        return {i, j};
                    }
                }
            }

            return {-1, -1};
        };

        auto last = getPos('a');
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            const auto next = getPos(s[i]);
            res += std::abs(last.first - next.first) + std::abs(last.second - next.second);
            last = next;
        }

        return res;
    }
};