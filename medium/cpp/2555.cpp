// https://leetcode.com/problems/maximize-win-from-two-segments/description/

class Solution
{
public:
    int maximizeWin(std::vector<int>& prizePositions, int k)
    {
        const auto n = std::size(prizePositions);

        std::vector<int> cnt(n);

        for (auto l = 0, r = 0; r < n; r++)
        {
            while (l < r && prizePositions[r] - prizePositions[l] > k)
            {
                l++;
            }

            cnt[r] = r - l + 1;
        }

        std::vector<int> pre(n);

        pre[0] = cnt[0];

        for (auto i = 1; i < n; i++)
        {
            pre[i] = std::max(cnt[i], pre[i - 1]);
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            res = std::max(res, cnt[i] + (i - cnt[i] >= 0 ? pre[i - cnt[i]] : 0));
        }

        return res;
    }
};