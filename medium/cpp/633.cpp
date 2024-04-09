// https://leetcode.com/problems/sum-of-square-numbers/description/

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (auto a = 0; 1LL * a * a <= c; a++)
        {
            auto b = static_cast<long long>(std::sqrt(c - a * a));

            if (b * b == c - a * a)
            {
                return true;
            }
        }

        return false;
    }
};