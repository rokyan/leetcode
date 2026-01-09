// https://leetcode.com/problems/minimum-cost-to-merge-sorted-lists/description/

class Solution
{
private:
    static constexpr long long inf = 1000'000'000'000'000LL;

public:
    long long minMergeCost(const std::vector<std::vector<int>>& lists)
    {
        const int n = lists.size();

        std::vector<int> median_per_mask(1 << n);
        std::vector<int> mask_len(1 << n);

        std::vector<int> buffer;
        buffer.reserve(2000);

        for (int mask = 1; mask < (1 << n); mask++)
        {
            int total_len = 0;

            for (int bit = 0; bit < n; bit++)
            {
                if (mask & (1 << bit))
                {
                    total_len += lists[bit].size();
                }
            }

            mask_len[mask] = total_len;

            buffer.clear();

            for (int bit = 0; bit < n; bit++)
            {
                if (mask & (1 << bit))
                {
                    for (int num : lists[bit])
                    {
                        buffer.push_back(num);
                    }
                }
            }

            const int mid = (total_len - 1) / 2;
            std::nth_element(buffer.begin(), std::next(buffer.begin(), mid), buffer.end());

            median_per_mask[mask] = buffer[mid];
        }

        std::vector<long long> dp(1 << n, inf);

        for (int bit = 0; bit < n; bit++)
        {
            dp[1 << bit] = 0;
        }

        for (int mask = 1; mask < (1 << n); mask++)
        {
            for (int sub_mask = mask; sub_mask > 0; sub_mask = (sub_mask - 1) & mask)
            {
                if (sub_mask != mask)
                {
                    dp[mask] = std::min(dp[mask], dp[sub_mask] + dp[mask ^ sub_mask] + mask_len[mask]
                        + std::abs(median_per_mask[sub_mask] - median_per_mask[mask ^ sub_mask]));
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};