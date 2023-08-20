// https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        auto s = 0;

        for (auto i = 0, t = 1; i < n; i++)
        {
            if (t == k / 2 + 1)
            {
                t = k;
            }

            s += t++;
        }

        return s;
    }
};