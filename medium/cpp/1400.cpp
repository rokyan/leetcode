// https://leetcode.com/problems/construct-k-palindrome-strings/description/

class Solution
{
public:
    bool canConstruct(std::string s, int k)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        auto p = 0;

        for (auto i = 0; i < 26 && k >= 0; i++)
        {
            if (freq[i] & 1)
            {
                k--;
            }

            p += freq[i] / 2;
        }

        return k >= 0 && p * 2 >= k;
    }
};