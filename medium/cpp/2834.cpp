// https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/

class Solution
{
private:
    static constexpr auto mod = 1000000007;

public:
    int minimumPossibleSum(int n, int target)
    {
        const auto t = std::min(target / 2, n);

        auto s = 1LL * t * (t + 1) / 2 % mod;

        const auto rem = n - t;

        if (rem > 0)
        {
            s += (0LL + target + target + rem - 1) * rem / 2 % mod;
        }

        return s % mod;
    }
};