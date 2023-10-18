// https://leetcode.com/problems/group-shifted-strings/description/

class Solution
{
public:
    std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings)
    {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, int> mapper;

        for (auto&& s : strings)
        {
            const auto& normalized = get_normalized(s);

            if (const auto it = mapper.find(normalized); it != std::end(mapper))
            {
                res[it->second].push_back(s);
            }
            else
            {
                mapper[normalized] = std::size(res);
                res.push_back({ s });
            }
        }

        return res;
    }

private:
    std::string get_normalized(std::string s)
    {
        const auto shift = s[0] - 'a';

        for (auto& c : s)
        {
            c = (c - 'a' - shift + 26) % 26 + 'a';
        }

        return s;
    }
};