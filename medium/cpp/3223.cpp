// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution
{
public:
    int minimumLength(const std::string& s)
    {
        std::array<int, 26> freq{ 0 };

        for (char c : s)
        {
            freq[c - 'a']++;
        }

        auto res = 0;

        for (auto i = 0; i < 26; i++)
        {
            if (freq[i])
            {
                res += 1 + (freq[i] % 2 == 0);
            }
        }

        return res;
    }
};