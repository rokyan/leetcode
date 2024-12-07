// https://leetcode.com/problems/zero-array-transformation-ii/description/

class Solution
{
public:
    int minZeroArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries)
    {
        auto l = 0;
        auto r = std::size(queries);

        while (l < r)
        {
            const auto mid = l + (r - l) / 2;

            if (check(nums, queries, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return check(nums, queries, l) ? l : -1;
    }

private:
    bool check(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries, int take)
    {
        const auto n = std::size(nums);
        std::vector<int> acc(n + 1);

        for (auto i = 0; i < take; i++)
        {
            const auto l = queries[i][0];
            const auto r = queries[i][1];
            const auto v = queries[i][2];

            acc[l] += v;
            acc[r + 1] -= v;
        }

        for (auto i = 0, s = 0; i < n; i++)
        {
            s += acc[i];

            if (s < nums[i])
            {
                return false;
            }
        }

        return true;
    }
};