// https://leetcode.com/problems/maximum-xor-of-subsequences/description/

class Solution
{
public:
    int maxXorSubsequences(const std::vector<int>& nums)
    {
        std::vector<int> basis;

        for (int x : nums)
        {
            for (int b : basis)
            {
                x = min(x, x ^ b);
            }

            if (x > 0)
            {
                basis.push_back(x);
            }
        }

        int res = 0;

        for (int b : basis)
        {
            res = max(res, res ^ b);
        }

        return res;
    }
};