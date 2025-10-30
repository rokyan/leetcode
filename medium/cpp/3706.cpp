// https://leetcode.com/problems/maximum-distance-between-unequal-words-in-array-ii/description/

class Solution
{
public:
    int maxDistance(const std::vector<std::string>& words)
    {
        std::unordered_map<std::string, int> firstPos;
        std::set<int> allPos;
        int res = 0;

        const int n = std::size(words);

        for (int i = 0; i < n; i++)
        {
            const std::string& word = words[i];

            if (const auto it = firstPos.find(word); it != std::end(firstPos))
            {
                allPos.erase(it->second);

                if (!allPos.empty())
                {
                    res = std::max(res, i - *std::begin(allPos) + 1);
                }

                allPos.insert(it->second);
            }
            else
            {
                if (!allPos.empty())
                {
                    res = std::max(res, i - *std::begin(allPos) + 1);
                }

                allPos.insert(i);
                firstPos[word] = i;                
            }
        }

        return res;
    }
};