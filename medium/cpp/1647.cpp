// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

class Solution
{
public:
    int minDeletions(std::string s)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        std::sort(std::begin(freq), std::end(freq), std::greater<>{});

        auto prev = freq[0];
        auto res = 0;

        for (auto i = 1; i < 26; i++)
        {
            if (freq[i] == 0)
            {
                break;
            }

            if (prev == 0)
            {
                res += freq[i];
            }
            else
            {
                while (freq[i] >= prev)
                {
                    res++;
                    freq[i]--;
                }
                
                prev = freq[i];
            }
        }

        return res;
    }
};