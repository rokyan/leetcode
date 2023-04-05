// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/

class Solution
{
public:
    int minOperations(int n)
    {
        std::vector<char> bits;

        while (n > 0)
        {
            bits.push_back(n % 2);
            n /= 2;
        }

        bits.push_back(0);
        bits.push_back(0);

        auto res = 0;

        for (auto i = 0, ones = 0; i < std::size(bits); )
        {
            if (bits[i] == 1)
            {
                ones++;
                i++;
            }
            else
            {
                if (ones == 0)
                {
                    i++;
                }
                else if (ones == 1)
                {
                    i++;
                    ones = 0;
                    res++;
                }
                else
                {
                    bits[i] = 1;
                    ones = 0;
                    res++;
                }
            }
        }

        return res;
    }
};