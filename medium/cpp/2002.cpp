// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/

class Solution
{
public:
    int maxProduct(const std::string& s)
    {
        const auto n = std::size(s);

        auto res = 0;

        for (auto mask = 1; mask < (1 << n); mask++)
        {
            for (auto subMask = (mask - 1 ) & mask; subMask > 0; subMask = (subMask - 1) & mask)
            {
                auto diffMask = mask ^ subMask;

                if (isPalindrome(s, diffMask) && isPalindrome(s, subMask))
                {
                    res = std::max(res, calcMaskLen(diffMask) * calcMaskLen(subMask));
                }
            }
        }

        return res;
    }

private:
    bool isPalindrome(const std::string& s, int mask)
    {
        int i = 0;
        int j = std::size(s) - 1;

        while (i < j)
        {
            while (!(mask & (1 << i)))
            {
                i++;
            }

            while (!(mask & (1 << j)))
            {
                j--;
            }

            if (s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int calcMaskLen(int mask)
    {
        auto res = 0;

        for (auto bit = 0; bit <= 12; bit++)
        {
            if (mask & (1 << bit))
            {
                res++;
            }
        }

        return res;
    }
};