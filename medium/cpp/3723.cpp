// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/

class Solution
{
public:
    std::string maxSumOfSquares(int num, int sum)
    {
        std::string res(num, '0');

        for (int i = 0; i < num; i++)
        {
            res[i] = '0' + std::min(sum, 9);
            sum -= std::min(sum, 9);
        }

        if (sum > 0)
        {
            return "";
        }

        return res;
    }
};