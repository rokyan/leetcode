// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution
{
public:
    int maximumLength(std::string s)
    {
        const auto n = std::size(s);

        for (auto len = static_cast<int>(n) - 2; len; len--)
        {
            std::map<std::string, int> cnt;

            for (auto i = 0; i + len - 1 < n; i++)
            {
                auto skip = false;

                for (auto j = i + 1; j < i + len && !skip; j++)
                {
                    if (s[j] != s[j - 1])
                    {
                        skip = true;
                    }
                }
                if (!skip && cnt[s.substr(i, len)]++ == 2)
                {
                    return len;
                }
            }
        }

        return -1;
    }
};