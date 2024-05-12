// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/

class Solution
{
public:
    int minimumDeletions(std::string word, int k)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : word)
        {
            freq[c - 'a']++;
        }

        std::sort(std::begin(freq), std::end(freq));

        auto start = 0;

        while (freq[start] == 0) start++;

        auto res = -1;

        for (auto i = start; i < 26; i++)
        {
            auto cur = 0;

            for (auto j = start; j < i; j++)
            {
                cur += freq[j];
            }

            for (auto j = i + 1; j < 26; j++)
            {
                if (freq[j] > freq[i] + k)
                {
                    cur += freq[j] - freq[i] - k;
                }
            }

            if (res == -1)
            {
                res = cur;
            }
            else
            {
                res = std::min(res, cur);
            }
        }

        return res;
    }
};