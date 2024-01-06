// https://leetcode.com/problems/find-right-interval/description/

class Solution
{
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals)
    {
        const auto n = std::size(intervals);

        std::vector<std::pair<int, int>> data(n);

        for (auto i = 0; i < n; i++)
        {
            data[i] = { intervals[i][0], i };
        }

        std::sort(std::begin(data), std::end(data));

        std::vector<int> res(n);

        for (auto i = 0; i < n; i++)
        {
            auto end = intervals[i][1];

            const auto it = std::lower_bound(std::cbegin(data), std::cend(data), std::make_pair(end, -1));

            res[i] = it == std::cend(data) ? -1 : it->second;
        }

        return res;
    }
};