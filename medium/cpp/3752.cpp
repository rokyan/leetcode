// https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target/description/

class Solution
{
public:
    std::vector<int> lexSmallestNegatedPerm(int n, long long target)
    {
        const long long sum = 1LL * n * (n + 1) / 2;

        if (target < -sum || target > sum || (sum - target) % 2 == 1)
        {
            return {};
        }

        long long val = (sum - target) / 2;

        std::vector<int> res(n);

        int start = 0;
        int end = n - 1;

        for (int num = n; num >= 1 && val >= 0; num--)
        {
            if (val >= num)
            {
                val -= num;
                res[start++] = -num;
            }
            else
            {
                res[end--] = num;
            }
        }

        return res;
    }
};