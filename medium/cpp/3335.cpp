// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int lengthAfterTransformations(const std::string& s, int t)
    {
        std::array<int, 26> freq;
        freq.fill(0);

        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        for (auto i = 0; i < t; i++)
        {
            std::array<int, 26> next;
            next.fill(0);

            for (auto c = 0; c + 1 < 26; c++)
            {
                next[c + 1] = freq[c];
            }

            next[0] += freq[25];
            next[0] %= mod;

            next[1] += freq[25];
            next[1] %= mod;

            freq = std::move(next);
        }

        auto len = 0;

        for (auto c = 0; c < 26; c++)
        {
            len += freq[c];
            len %= mod;
        }

        return len;
    }
};