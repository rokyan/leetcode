// https://leetcode.com/problems/construct-string-with-repeat-limit/description/

class Solution
{
public:
    std::string repeatLimitedString(std::string s, int repeatLimit)
    {
        std::array<int, 26> cnt{};

        for (auto c : s)
        {
            cnt[c - 'a']++;
        }

        std::string res;
        res.reserve(std::size(res));

        for (auto i = 25; i >= 0; )
        {
            for (auto j = 0; j < repeatLimit && cnt[i] > 0; j++)
            {
                res.push_back('a' + i);
                cnt[i]--;
            }

            if (cnt[i] == 0)
            {
                i--;
                continue;
            }

            auto found = false;

            for (auto k = i - 1; k >= 0; k--)
            {
                if (cnt[k] > 0)
                {
                    res.push_back('a' + k);
                    cnt[k]--;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                break;
            }
        }

        return res;
    }
};