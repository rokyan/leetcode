// https://leetcode.com/problems/apply-substitutions/description/

class Solution
{
public:
    std::string applySubstitutions(
        const std::vector<std::vector<std::string>>& replacements,
        const std::string& text)
    {
        return solve(text, replacements);
    }

private:
    std::string solve(
        std::string_view sw,
        const std::vector<std::vector<std::string>>& replacements)
    {
        std::string res;
        res.reserve(std::size(sw));

        for (auto i = 0; i < std::size(sw); i++)
        {
            if (sw[i] == '%')
            {
                auto j = i + 1;

                while (sw[j] != '%')
                {
                    j++;
                }

                const auto next = sw.substr(i + 1, j - 1 - (i + 1) + 1);
                auto found = false;

                i = j;

                for (const auto& e : replacements)
                {
                    const auto& target = e[0];
                    const auto& r = e[1];

                    if (next == target)
                    {
                        found = true;
                        res += solve(r, replacements);
                        break;
                    }
                }

                if (!found)
                {
                    res += solve(next, replacements);
                }
            }
            else
            {
                res.push_back(sw[i]);
            }
        }

        return res;
    }
};