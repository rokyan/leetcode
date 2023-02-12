// https://leetcode.com/problems/substring-xor-queries/description/

class Solution
{
public:
    std::vector<std::vector<int>> substringXorQueries(std::string s, std::vector<std::vector<int>>& queries)
    {
        const auto n = static_cast<int>(std::size(s));

        std::unordered_map<int, std::pair<int, int>> pos;

        for (auto i = 0; i < n; i++)
        {
            for (auto len = 1; len < 32; len++)
            {
                if (len > 1 && s[i] == '0')
                {
                    continue;
                }

                if (i + len - 1 < n)
                {
                    const auto sub = std::stoi(s.substr(i, len), nullptr, 2);

                    if (const auto it = pos.find(sub); it == std::end(pos))
                    {
                        pos.insert({ sub, { i, i + len - 1 } });
                    }
                }
            }
        }

        const auto q = static_cast<int>(std::size(queries));

        std::vector<std::vector<int>> res(q);

        for (auto i = 0; i < q; i++)
        {
            const auto& first = queries[i][0];
            const auto& second = queries[i][1];

            const auto val = first ^ second;

            if (const auto it = pos.find(val); it == std::end(pos))
            {
                res[i] = { -1, -1 };
            }
            else
            {
                res[i] = { it->second.first, it->second.second };
            }
        }

        return res;
    }
};