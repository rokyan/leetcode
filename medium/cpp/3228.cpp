// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/

class Solution
{
public:
    int maxOperations(const std::string& s)
    {
        auto last = 0;
        auto res = 0;

        const auto n = static_cast<int>(std::size(s));

        for (auto i = n - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                if (s[i + 1] == '1')
                {
                    res += last;
                }
                else
                {
                    res += ++last;
                }
            }
        }

        return res;
    }
};