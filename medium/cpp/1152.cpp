// https://leetcode.com/problems/analyze-user-website-visit-pattern/description/

class Solution
{
public:
    std::vector<std::string> mostVisitedPattern(
        const std::vector<std::string>& username,
        const std::vector<int>& timestamp,
        const std::vector<std::string>& website)
    {
        std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> data;

        const auto n = std::size(username);

        for (auto i = 0; i < n; i++)
        {
            data[username[i]].emplace_back(timestamp[i], website[i]);
        }

        std::unordered_map<std::string, int> freq;
        auto cnt = -1;
        auto pattern = std::string{};

        for (auto& [_, value] : data)
        {
            if (std::size(value) < 3)
            {
                continue;
            }

            std::sort(std::begin(value), std::end(value));

            std::unordered_set<std::string> dedup;

            for (auto i1 = 0; i1 + 2 < std::size(value); i1++)
            {
                for (auto i2 = i1 + 1; i2 + 1 < std::size(value); i2++)
                {
                    for (auto i3 = i2 + 1; i3 < std::size(value); i3++)
                    {
                        dedup.insert(value[i1].second + "#" + value[i2].second + "#" + value[i3].second);
                    }
                }
            }

            for (const auto& e : dedup)
            {
                const auto cur = ++freq[e];

                if (cur > cnt || cur == cnt && e < pattern)
                {
                    pattern = e;
                    cnt = cur;
                }
            }
        }

        std::vector<std::string> ws { "" };

        for (auto c : pattern)
        {
            if (c == '#')
            {
                ws.push_back("");
            }
            else
            {
                ws.back().push_back(c);
            }
        }

        return ws;
    }
};