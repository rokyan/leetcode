// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

class Solution
{
public:
    int minSwaps(std::string s)
    {
        auto open = 0;
        auto cnt = 0;

        for (auto c : s)
        {
            if (c == '[')
            {
                open++;
            }
            else
            {
                if (open)
                {
                    open--;
                }
                else
                {
                    cnt++;
                }
            }
        }

        return (cnt + 1) / 2;
    }
};