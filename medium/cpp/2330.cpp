// https://leetcode.com/problems/valid-palindrome-iv/description/

class Solution
{
public:
    bool makePalindrome(std::string s)
    {
        const auto n = std::size(s);
        auto df = 0;

        for (auto i = 0; i < n / 2 && df < 3; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                df++;
            }
        }

        return df <= 2;
    }
};