// https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/description/

class Solution
{
public:
    std::vector<std::string> shortestSubstrings(const std::vector<std::string>& arr)
    {
        std::unordered_map<std::string_view, int> freq;

        for (const auto& s : arr)
        {
            const auto sw = std::string_view{s};

            std::unordered_set<std::string_view> filter;

            for (auto i = 0; i < std::size(sw); i++)
            {
                for (auto j = i; j < std::size(sw); j++)
                {
                    const auto sub = sw.substr(i, j - i + 1);

                    if (filter.insert(sub).second)
                    {
                        freq[sw.substr(i, j - i + 1)]++;
                    }
                }
            }
        }

        std::vector<std::string> res;
        res.reserve(std::size(arr));

        for (const auto& s : arr)
        {
            const auto sw = std::string_view{s};

            std::string cur;

            for (auto i = 0; i < std::size(sw); i++)
            {
                for (auto j = i; j < std::size(sw); j++)
                {
                    const auto sub = sw.substr(i, j - i + 1);

                    if (freq[sub] == 1)
                    {
                        if (cur.empty() || std::size(sub) < std::size(cur) ||
                            std::size(sub) == std::size(cur) && cur > sub)
                        {
                            cur = sub;
                        }
                    }
                }
            }

            res.push_back(std::move(cur));
        }

        return res;
    }
};