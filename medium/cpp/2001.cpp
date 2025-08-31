// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

class Solution
{
public:
    long long interchangeableRectangles(const std::vector<std::vector<int>>& rectangles)
    {
        std::map<std::pair<int, int>, int> cnt;

        for (const auto& rec : rectangles)
        {
            const auto val = gcd(rec[0], rec[1]);
            cnt[{rec[0] / val, rec[1] / val}]++;
        }

        auto res = 0LL;

        for (const auto [_, times] : cnt)
        {
            res += 1LL * times * (times - 1) / 2;
        }

        return res;
    }

private:
    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};