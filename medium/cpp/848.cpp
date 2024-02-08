// https://leetcode.com/problems/shifting-letters/

class Solution
{
public:
    std::string shiftingLetters(std::string s, std::vector<int>& shifts)
    {
        const auto n = static_cast<int>(std::size(s));

        for (auto i = n, acc = 0; i--; )
        {
            s[i] = (s[i] - 'a' + (acc += shifts[i])) % 26 + 'a';
            acc %= 26;
        }

        return s;
    }
};