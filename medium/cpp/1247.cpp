// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

class Solution
{
public:
    int minimumSwap(std::string s1, std::string s2)
    {
        int cnt[2] = { 0 };
        
        for (std::size_t pos = 0; pos < std::size(s1); pos++)
        {
            if (s1[pos] != s2[pos])
            {
                if (s1[pos] == 'x')
                {
                    cnt[0]++;
                }
                else
                {
                    cnt[1]++;
                }
            }
        }
        
        const auto s = cnt[0] + cnt[1];
        
        if (s & 1)
        {
            return -1;
        }
        
        auto car = cnt[0] / 2 + cnt[1] / 2;
        
        cnt[0] %= 2;
        cnt[1] %= 2;
        
        return (cnt[0] + cnt[1]) == 1 ? -1 : car + (cnt[0] + cnt[1]);
    }
};