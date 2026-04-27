// https://leetcode.com/problems/check-digitorial-permutation/description/

class Solution
{
public:
    bool isDigitorialPermutation(int n)
    {
        std::array<int, 10> facts;

        for (int d = 0; d < 10; d++)
        {
            facts[d] = d;

            if (d == 0)
            {
                facts[d] = 1;
            }
            else
            {
                facts[d] *= facts[d - 1];
            }
        }

        std::vector<int> digits;

        while (n > 0)
        {
            digits.push_back(n % 10);
            n /= 10;
        }

        std::ranges::sort(digits);

        do
        {
            if (digits[0] == 0)
            {
                continue;
            }

            int fs = 0;
            int x = 0;

            for (auto d : digits)
            {
                x = 10 * x + d;
                fs += facts[d];
            }

            if (fs == x)
            {
                return true;
            }
        }
        while
        (
            std::next_permutation(digits.begin(), digits.end())
        );

        return false;
    }
};