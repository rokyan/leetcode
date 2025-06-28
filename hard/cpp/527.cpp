// https://leetcode.com/problems/word-abbreviation/description/

class Solution
{
public:
    std::vector<std::string> wordsAbbreviation(const std::vector<std::string>& words)
    {
        const auto n = std::size(words);

        std::vector<std::string> res(n);

        std::unordered_map<std::string, std::vector<std::pair<std::string_view, int>>> same;

        for (auto i = 0; i < n; i++)
        {
            const auto len = std::size(words[i]);

            if (len < 4)
            {
                res[i] = words[i];
            }
            else
            {
                const auto abbr = words[i].front() + std::to_string(len - 2) + words[i].back();
                same[abbr].emplace_back(words[i], i);
            }
        }

        for (const auto& [_, swp] : same)
        {
            std::vector<char> used(std::size(swp));
            const auto wordSize = std::size(swp.front().first);

            for (auto prefLen = 1; prefLen <= wordSize - 3; prefLen++)
            {
                std::unordered_map<std::string_view, int> cnt;

                for (auto i = 0; i < std::size(swp); i++)
                {
                    if (used[i])
                    {
                        continue;
                    }

                    const auto& word = swp[i].first;
                    cnt[word.substr(0, prefLen)]++;
                }

                for (auto i = 0; i < std::size(swp); i++)
                {
                    if (used[i])
                    {
                        continue;
                    }

                    const auto& word = swp[i].first;
                    const auto pref = word.substr(0, prefLen);
                    if (cnt[pref] == 1)
                    {
                        used[i] = true;
                        res[swp[i].second] = std::string{pref} + std::to_string(wordSize - 1 - prefLen) + word.back();
                    }
                }
            }

            for (auto i = 0; i < std::size(swp); i++)
            {
                if (!used[i])
                {
                    res[swp[i].second] = swp[i].first;
                }
            }
        }

        return res;
    }
};