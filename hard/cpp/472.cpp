// https://leetcode.com/problems/concatenated-words/description/

class Solution
{
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words)
    {
        std::unordered_set<std::string_view> probe(std::begin(words), std::end(words));

        std::vector<char> dp(30);

        std::vector<std::string> res;

        for (const auto& word : words)
        {
            std::fill(std::begin(dp), std::end(dp), 0);

            for (auto i = 0; i < std::size(word); i++)
            {
                for (auto j = 0; j <= i; j++)
                {
                    if (const auto it = probe.find(std::string_view(word).substr(j, i - j + 1)); it != std::end(probe))
                    {
                        if (j == 0 && i + 1 < std::size(word) || j > 0 && dp[j - 1] > 0)
                        {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }

            if (dp[std::size(word) - 1])
            {
                res.push_back(word);
            }
        }

        return res;
    }
};