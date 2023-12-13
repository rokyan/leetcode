// https://leetcode.com/problems/number-of-same-end-substrings/description/

class Solution
{
public:
    std::vector<int> sameEndSubstringCount(std::string s, std::vector<std::vector<int>>& queries)
    {
        std::vector<std::vector<int>> cnt(26, std::vector<int>(std::size(s)));

        for (auto i = 0; i < std::size(s); i++)
        {
            cnt[s[i] - 'a'][i]++;

            if (i > 0)
            {
                for (auto c = 0; c < 26; c++)
                {
                    cnt[c][i] += cnt[c][i - 1];
                }
            }
        }

        std::vector<int> res(std::size(queries));

        for (auto q = 0; q < std::size(queries); q++)
        {
            const auto left = queries[q][0];
            const auto right = queries[q][1];

            for (auto c = 0; c < 26; c++)
            {
                auto t = cnt[c][right] - (left > 0 ? cnt[c][left - 1] : 0);
                res[q] += t + t * (t - 1) / 2;
            }
        }

        return res;
    }
};