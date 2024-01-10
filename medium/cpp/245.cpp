// https://leetcode.com/problems/shortest-word-distance-iii/

class Solution
{
public:
    int shortestWordDistance(std::vector<std::string>& wordsDict, std::string word1, std::string word2)
    {
        const auto n = static_cast<int>(std::size(wordsDict));

        auto res = n;
        auto same = word1 == word2;

        for (auto i = 0, prev = -1; i < n; i++)
        {
            if (wordsDict[i] == word1 || wordsDict[i] == word2)
            {
                if (prev != -1)
                {
                    if (wordsDict[prev] != wordsDict[i] || same)
                    {
                        res = std::min(res, i - prev);
                    }
                }

                prev = i;
            }
        }

        return res;
    }
};