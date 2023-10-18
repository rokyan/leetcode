// https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/

class Solution
{
public:
    bool makeStringsEqual(std::string s, std::string target)
    {
        const auto x = std::count(std::begin(s), std::end(s), '1');
        const auto y = std::count(std::begin(target), std::end(target), '1');

        if (x == 0)
        {
            return y == 0;
        }

        return y >= 1;
    }
};