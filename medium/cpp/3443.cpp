// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/

class Solution
{
public:
    int maxDistance(const std::string& s, int k)
    {
        std::array<int, 4> cnt;
        cnt.fill(0);

        auto res = 0;

        for (char c : s)
        {
            if (c == 'N')
            {
                cnt[0]++;
            }

            if (c == 'E')
            {
                cnt[1]++;
            }

            if (c == 'S')
            {
                cnt[2]++;
            }

            if (c == 'W')
            {
                cnt[3]++;
            }

            auto cur = std::abs(cnt[0] - cnt[2]) + std::abs(cnt[1] - cnt[3]);

            const auto fix = std::min(cnt[0], cnt[2]);
            cur += 2 * std::min(fix, k);

            if (fix < k)
            {
                const auto nextFix = std::min(cnt[1], cnt[3]);
                cur += 2 * std::min(k - fix, nextFix);
            }

            res = std::max(res, cur);
        }

        return res;
    }
};