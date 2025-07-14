// https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-i/description/

class Solution
{
public:
    int longestPalindrome(const std::string& s, const std::string& t)
    {
        auto res = 0;

        const auto conc = s + t;

        for (auto firstS = 0; firstS < std::size(s); firstS++)
        {
            for (auto lastS = firstS; lastS <= std::size(s); lastS++)
            {
                for (auto firstT = std::size(s); firstT < std::size(conc); firstT++)
                {
                    for (auto lastT = firstT; lastT <= std::size(conc); lastT++)
                    {
                        auto len = lastS - firstS + lastT - firstT;

                        if (len > res && check(conc, firstS, lastS, firstT, lastT))
                        {
                            res = std::max<int>(res, len);
                        }
                    }
                }
            }
        }
        
        return res;
    }

private:
    bool check(const std::string& conc,
        int firstS, int lastS,
        int firstT, int lastT)
    {
        const auto total = lastS - firstS + lastT - firstT;

        for (auto l = firstS, r = lastT - 1; l < r; l++, r--)
        {
            if (l == lastS)
            {
                l = firstT;
            }

            if (r == firstT - 1)
            {
                r = lastS - 1;
            }

            if (l >= r)
            {
                break;
            }

            if (conc[l] != conc[r])
            {
                return false;
            }
        }
        return true;
    }
};