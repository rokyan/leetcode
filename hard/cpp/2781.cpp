// https://leetcode.com/problems/length-of-the-longest-valid-substring/description/

class Solution
{
public:
    int longestValidSubstring(std::string word, std::vector<std::string>& forbidden)
    {
        std::unordered_set<std::string_view> probe(std::begin(forbidden), std::end(forbidden));

        auto res = 0;
        auto view = std::string_view{ word };

        for (auto i = 0, left = 0; i < std::size(word); i++)
        {
            auto len = 0;

            for (auto j = 1; j <= 10 && i - j + 1 >= 0; j++)
            {
                if (const auto it = probe.find(view.substr(i - j + 1, j)); it == std::end(probe))
                {
                    len = j;
                }
                else
                {
                    break;
                }
            }

            if (len == 10)
            {
                len = std::max(len, i + 1);
            }

            if (len == 0)
            {
                left = i + 1;
            }
            else
            {
                left = std::max(left, i - len + 1);
                res = std::max(res, i - left + 1);
            }
        }

        return res;
    }
};