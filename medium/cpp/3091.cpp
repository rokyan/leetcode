// https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/

class Solution
{
public:
    int minOperations(int k)
    {
        int res = -1;

        for (auto i = 0; i < k; i++)
        {
            const auto upd = i + k / (1 + i) + (k % (1 + i) != 0) - 1;
            res = res == -1 ? upd : std::min(res, upd);
        }

        return res;
    }
};