// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int numSubseq(std::vector<int>& nums, int target)
    {
        std::sort(std::begin(nums), std::end(nums));

        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> pow(n);
        pow[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            pow[i] = pow[i - 1] * 2 % mod;
        }

        auto res = 0;

        for (auto l = 0, r = n - 1; ; l++)
        {
            while (r >= l && nums[l] + nums[r] > target)
            {
                r--;
            }

            if (r < l)
            {
                break;
            }

            res += pow[r - l];
            res %= mod;
        }

        return res;
    }
};