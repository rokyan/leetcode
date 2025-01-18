// https://leetcode.com/problems/find-mirror-score-of-a-string/description/

class Solution
{
public:
    long long calculateScore(const std::string& s)
    {
        std::vector<std::vector<int>> q(26);
        auto res = 0LL;

        for (auto i = 0; i < std::size(s); i++)
        {
            const auto code = s[i] - 'a';
            const auto rev = 25 - code;

            if (q[rev].empty())
            {
                q[code].push_back(i);
            }
            else
            {
                res += i - q[rev].back();
                q[rev].pop_back();
            }
        }

        return res;
    }
};