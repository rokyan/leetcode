// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/

class Solution
{
public:
    int numKLenSubstrNoRepeats(std::string s, int k)
    {
        auto res = 0;

        std::array<int, 26> freq{ 0 };

        for (auto i = 0, rep = 0; i < std::size(s); i++)
        {
            if (freq[s[i] - 'a']++ == 1)
            {
                rep++;
            }

            if (i >= k && freq[s[i - k] - 'a']-- == 2)
            {
                rep--;
            }

            if (i >= k - 1 && rep == 0)
            {
                res++;
            }
        }

        return res;
    }
};