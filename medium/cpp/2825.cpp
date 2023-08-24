// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/

class Solution
{
public:
    bool canMakeSubsequence(std::string str1, std::string str2)
    {
        auto pos = 0;

        for (auto i = 0; i < std::size(str1) && pos < std::size(str2); i++)
        {
            if (str2[pos] == str1[i] || str2[pos] == (str1[i] - 'a' + 1) % 26 + 'a')
            {
                pos++;
            }
        }

        return pos == std::size(str2);
    }
};