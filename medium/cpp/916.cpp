// https://leetcode.com/problems/word-subsets/description/

class Solution
{
public:
    std::vector<std::string> wordSubsets(const std::vector<std::string>& words1,
        const std::vector<std::string>& words2)
    {
        std::array<int, 26> max_freq{0};

        for (const auto& word : words2)
        {
            std::array<int, 26> freq{0};

            for (auto c : word)
            {
                freq[c - 'a']++;
            }

            for (auto i = 0; i < 26; i++)
            {
                max_freq[i] = std::max(max_freq[i], freq[i]);
            }
        }

        std::vector<std::string> res;

        for (const auto& word : words1)
        {
            std::array<int, 26> freq{0};

            for (auto c : word)
            {
                freq[c - 'a']++;
            }

            auto check = true;

            for (auto i = 0; i < 26 && check; i++)
            {
                if (freq[i] < max_freq[i])
                {
                    check = false;
                }
            }

            if (check)
            {
                res.push_back(word);
            }
        }

        return res;
    }
};