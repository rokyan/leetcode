// https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/

class Solution
{
public:
    long long numberOfSubstrings(std::string s)
    {
        auto res = 0LL;

        std::array<int, 26> cnt{ 0 };

        for (auto c : s)
        {
            cnt[c - 'a']++;
            res += cnt[c - 'a'];
        }

        return res;
    }
};