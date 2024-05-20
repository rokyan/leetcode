// https://leetcode.com/problems/count-pairs-of-equal-substrings-with-minimum-difference/description/

class Solution
{
public:
    int countQuadruples(std::string firstString, std::string secondString)
    {
        const int n = std::size(firstString);
        const int m = std::size(secondString);

        std::vector<int> last(26, -1);

        for (auto i = 0; i < m; i++)
        {
            last[secondString[i] - 'a'] = i;
        }

        auto res = 0;
        auto min_diff = 2 * (n + m);

        for (auto c = 0; c < 26; c++)
        {
            if (last[c] == -1)
            {
                continue;
            }

            auto found = false;
            auto diff = 2 * (n + m);

            for (auto i = 0; i < n && !found; i++)
            {
                if (firstString[i] == 'a' + c)
                {
                    found = true;
                    diff = std::min(diff, i - last[c]);
                }
            }

            if (found)
            {
                if (diff < min_diff)
                {
                    min_diff = diff;
                    res = 1;
                }
                else if (diff == min_diff)
                {
                    res++;
                }
            }
        }

        return res;
    }
};