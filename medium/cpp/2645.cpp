// https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/

class Solution
{
public:
    int addMinimum(std::string word)
    {
        std::array<char, 3> let { 'a', 'b', 'c' };
        auto p = 0;
        auto res = 0;

        for (auto i = 0; i < std::size(word); i++)
        {
            while (let[p] != word[i])
            {
                res++;
                p = (p + 1) % 3;
            }

            p = (p + 1) % 3;
        }

        while (p != 0)
        {
            res++;
            p = (p + 1) % 3;
        }

        return res;
    }
};