// https://leetcode.com/problems/can-make-palindrome-from-substring/

class Solution
{
public:
    std::vector<bool> canMakePaliQueries(std::string s, std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(s);

        std::vector<std::vector<int>> pref(26, std::vector<int>(n));

        for (auto i = 0; i < n; i++)
        {
            pref[s[i] - 'a'][i]++;

            if (i > 0)
            {
                for (auto j = 0; j < 26; j++)
                {
                    pref[j][i] += pref[j][i - 1];
                }
            }
        }

        std::vector<bool> res(std::size(queries));

        for (auto q = 0; q < std::size(queries); q++)
        {
            const auto l = queries[q][0];
            const auto r = queries[q][1];
            const auto k = queries[q][2];

            auto odd = 0;

            for (auto i = 0; i < 26 && odd / 2 <= k; i++)
            {
                auto diff = pref[i][r];

                if (l > 0)
                {
                    diff -= pref[i][l - 1];
                }

                odd += diff % 2;
            }

            res[q] = odd / 2 <= k;
        }

        return res;
    }
};