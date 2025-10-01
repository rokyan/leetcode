// https://leetcode.com/problems/number-of-matching-subsequences/description/

class Solution
{
public:
    int numMatchingSubseq(const std::string& s, const std::vector<std::string>& words)
    {
        const int n = std::size(s);
        const int m = std::size(words);

        std::vector<std::vector<std::pair<int, int>>> buckets(26);

        for (int i = 0; i < m; i++)
        {
            buckets[words[i][0] - 'a'].emplace_back(i, 0);
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            const auto e = std::move(buckets[s[i] - 'a']);
            buckets[s[i] - 'a'].clear();

            for (const auto& [idx, pos] : e)
            {
                if (pos + 1 == std::size(words[idx]))
                {
                    res++;
                }
                else
                {
                    buckets[words[idx][pos + 1] - 'a'].emplace_back(idx, pos + 1);
                }
            }
        }

        return res;
    }
};