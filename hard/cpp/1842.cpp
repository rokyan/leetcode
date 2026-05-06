// https://leetcode.com/problems/next-palindrome-using-same-digits/description/

class Solution
{
public:
    std::string nextPalindrome(std::string& num)
    {
        const int n = num.size();

        if (!std::next_permutation(num.begin(), num.begin() + n / 2))
        {
            return "";
        }

        for (int i = 0; i < n / 2; i++)
        {
            num[n - 1 - i] = num[i];
        }

        return num;
    }
};