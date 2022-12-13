// https://leetcode.com/problems/minimize-xor/description/

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        auto ones = 0;

        for (auto bit = 0; bit < 32; bit++)
        {
            if (num2 & (1 << bit))
            {
                ones++;
            }
        }

        auto ans = 0;

        for (auto bit = 31; bit >= 0 && ones; bit--)
        {
            if (num1 & (1 << bit))
            {
                ones--;
                ans |= (1 << bit);
            }
        }

        for (auto bit = 0; bit < 32 && ones; bit++)
        {
            if (!(num1 & (1 << bit)))
            {
                ones--;
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};