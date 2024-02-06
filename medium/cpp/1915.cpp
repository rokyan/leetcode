// https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution
{
public:
    long long wonderfulSubstrings(std::string word)
    {
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;

        auto res = 0LL;

        for (auto i = 0, mask = 0; i < std::size(word); i++)
        {
            mask ^= 1 << (word[i] - 'a');
            res += cnt[mask];

            for (auto b = 0; b < 10; b++)
            {
                res += cnt[mask ^ (1 << b)];
            }

            cnt[mask]++;
        }

        return res;
    }
};