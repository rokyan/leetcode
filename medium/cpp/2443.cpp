// https://leetcode.com/problems/sum-of-number-and-its-reverse/description/

class Solution
{
public:
    bool sumOfNumberAndReverse(int num)
    {
        for (auto first = 0; first <= num; first++)
        {
            auto last = 0;
            auto cp = first;

            while (cp > 0)
            {
                last = 10 * last + cp % 10;
                cp /= 10;
            }

            if (first + last == num)
            {
                return true;
            }
        }

        return false;
    }
};