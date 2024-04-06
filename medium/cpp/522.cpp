// https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/

class Solution
{
public:
    int findLUSlength(std::vector<std::string>& strs)
    {
        auto res = -1;

        for (auto i = 0; i < std::size(strs); i++)
        {
            const auto& str = strs[i];
            const auto len = std::size(str);

            for (auto mask = 0; mask < (1 << len); mask++)
            {
                auto sub = std::string{};
                sub.reserve(len);

                for (auto bit = 0; bit < len; bit++)
                {
                    if (mask & (1 << bit))
                    {
                        sub.push_back(str[bit]);
                    }
                }

                if (static_cast<int>(std::size(sub)) <= res)
                {
                    continue;
                }

                auto matched = false;

                for (auto j = 0; j < std::size(strs) && !matched; j++)
                {
                    if (i != j)
                    {
                        auto p = 0;

                        for (auto k = 0; p < std::size(sub) && k < std::size(strs[j]); k++)
                        {
                            if (sub[p] == strs[j][k])
                            {
                                p++;
                            }
                        }

                        if (p == std::size(sub))
                        {
                            matched = true;
                        }
                    }
                }

                if (!matched)
                {
                    res = std::max(res, static_cast<int>(std::size(sub)));
                }
            }
        }

        return res;
    }
};