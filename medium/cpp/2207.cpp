// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

class Solution
{
public:
    long long maximumSubsequenceCount(std::string text, std::string pattern)
    {
        auto res1 = 0LL;

        for (auto i = 0, cnt = 1; i < std::size(text); i++)
        {
            if (text[i] == pattern[1])
            {
                res1 += cnt;
            }
            
            if (text[i] == pattern[0])
            {
                cnt++;
            }
        }

        text.push_back(pattern[1]);

        auto res2 = 0LL;

        for (auto i = 0, cnt = 0; i < std::size(text); i++)
        {
            if (text[i] == pattern[1])
            {
                res2 += cnt;
            }
            
            if (text[i] == pattern[0])
            {
                cnt++;
            }
        }

        return std::max(res1, res2);
    }
};