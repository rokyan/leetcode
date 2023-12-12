// https://leetcode.com/problems/number-of-divisible-substrings/description/

class Solution
{
public:
    int countDivisibleSubstrings(std::string word)
    {
        std::array<int, 26> mapping {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9};

        auto res = 0;

        for (auto i = 0; i < std::size(word); i++)
        {
            auto s = 0;

            for (auto j = i; j < std::size(word); j++)
            {
                s += mapping[word[j] - 'a'];

                if (s % (j - i + 1) == 0)
                {
                    res++;
                }
            }
        }

        return res;
    }
};