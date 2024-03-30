// https://leetcode.com/problems/camelcase-matching/description/

class Solution
{
public:
    std::vector<bool> camelMatch(std::vector<std::string>& queries, std::string pattern)
    {
        const auto n = std::size(queries);

        std::vector<bool> res(n);

        for (auto i = 0; i < n; i++)
        {
            auto p = 0;

            for (auto c : queries[i])
            {
                if (p < std::size(pattern) && pattern[p] == c)
                {
                    p++;
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    p = -1;
                    break;
                }
            }

            res[i] = p == std::size(pattern);
        }

        return res;
    }
};