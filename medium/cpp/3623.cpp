// https://leetcode.com/problems/count-number-of-trapezoids-i/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int countTrapezoids(const std::vector<std::vector<int>>& points)
    {
        std::map<int, int> byY;

        for (const auto& point : points)
        {
            byY[point[1]]++;
        }

        auto acc = 0;
        auto res = 0;

        for (const auto& [_, cnt] : byY)
        {
            const auto cur = 1LL * (cnt - 1) * cnt / 2 % mod;

            res += 1LL * acc * cur % mod;
            res %= mod;

            acc += cur;
            acc %= mod;
        }

        return res;
    }
};