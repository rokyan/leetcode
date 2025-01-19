// https://leetcode.com/problems/count-special-subsequences/description/

class Solution
{
public:
    long long numberOfSubsequences(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        auto res = 0LL;

        std::unordered_map<int, int> cnt;

        for (auto r = 0; r < n; r++)
        {
            auto q = r - 2;

            if (q >= 0)
            {
                for (auto p = q - 2; p >= 0; p--)
                {
                    auto x = nums[q];
                    auto y = nums[p];
                    norm(x, y);
                    cnt[1001 * x + y]++;
                }
            }
            for (auto s = r + 2; s < n; s++)
            {
                auto x = nums[r];
                auto y = nums[s];
                norm(x, y);

                if (const auto it = cnt.find(1001 * x + y); it != std::end(cnt))
                {
                    res += it->second;
                }
            }
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

    void norm(int& x, int& y)
    {
        const auto d = gcd(x, y);
        x /= d;
        y /= d;
    }
};