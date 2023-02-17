// https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/

class Solution
{
public:
    std::vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum & 1)
        {
            return {};
        }

        std::vector<long long> res;

        for (auto num = 2LL; ; num += 2)
        {
            if (finalSum < num)
            {
                break;
            }

            finalSum -= num;
            res.push_back(num);
        }

        res.back() += finalSum;

        return res;
    }
};