// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

class Solution
{
public:
    std::vector<long long> sumOfThree(long long num)
    {
        if (num % 3 != 0)
        {
            return {};
        }
        
        return { num / 3 - 1, num / 3, num / 3 + 1 };
    }
};