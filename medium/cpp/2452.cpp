// https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/

class Solution
{
public:
    std::vector<std::string> twoEditWords(std::vector<std::string>& queries, std::vector<std::string>& dictionary)
    {
        const auto n = std::size(queries);

        std::vector<std::string> res;
        res.reserve(n);

        for (const auto& query : queries)
        {
            for (const auto& word : dictionary)
            {
                auto dist = 0;

                for (auto pos = 0; pos < std::size(word) && dist <= 2; pos++)
                {
                    if (query[pos] != word[pos])
                    {
                        dist++;
                    }
                }

                if (dist <= 2)
                {
                    res.push_back(query);
                    break;
                }
            }
        }

        return res;
    }
};