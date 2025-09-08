// https://leetcode.com/problems/minimum-operations-to-transform-string/description/

class Solution
{
public:
    int minOperations(const std::string& s)
    {
        auto hasOnlyA = true;

        for (auto c : s)
        {
            if (c != 'a')
            {
                hasOnlyA = false;
                break;
            }
        }

        if (hasOnlyA)
        {
            return 0;
        }

        auto minChar = 'z';

        for (auto c : s)
        {
            if (c != 'a')
            {
                minChar = std::min(minChar, c);
            }
        }

        return ('a' - minChar + 26);
    }
};