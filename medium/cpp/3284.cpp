// https://leetcode.com/problems/sum-of-consecutive-subarrays/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int getSum(const std::vector<int>& nums)
    {
        auto res = getSum(nums, [](int x, int y) { return x == y + 1; }) + getSum(nums, [](int x, int y) { return x == y - 1; });
        res %= mod;
        res -= std::accumulate(std::cbegin(nums), std::cend(nums), 0LL) % mod;
        return (res + mod) % mod;
    }

private:
    template<typename F>
    int getSum(const std::vector<int>& nums, F func)
    {
        auto acc = static_cast<long long>(nums[0]);
        auto res = acc;
        auto times = 1;

        for (auto i = 1; i < std::size(nums); i++)
        {
            if (func(nums[i], nums[i - 1]))
            {
                acc += 1LL * ++times * nums[i];
            }
            else
            {
                acc = nums[i];
                times = 1;
            }

            acc %= mod;
            res += acc;
            res %= mod;
        }

        return res;
    }
};