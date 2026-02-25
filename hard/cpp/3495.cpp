// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/

class Solution
{
public:
    long long minOperations(const std::vector<std::vector<int>>& queries)
    {
        long long res = 0;

        for (const auto& query : queries)
        {
            res += (calc(query[1]) - calc(query[0] - 1) + 1) / 2;
        }

        return res;
    }

private:
    long long calc(int value)
    {
        if (value == 0)
        {
            return 0;
        }
    
        long long start = 1;
        int contribution = 1;        
        long long res = 0;

        while (start * 4 <= value)
        {
            res += start * contribution * 3;
            contribution++;
            start *= 4;
        }

        res += contribution * (value - start + 1);

        return res;
    }
};