// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs-ii/description/

class Solution
{
public:
    int minimumTime(std::vector<int>& jobs, std::vector<int>& workers)
    {
        std::ranges::sort(jobs, std::greater<int>{});
        std::ranges::sort(workers, std::greater<int>{});

        auto res = 0;

        for (auto i = 0; i < std::size(jobs); i++)
        {
            res = std::max(res, (workers[i] + jobs[i] - 1) / workers[i]);
        }

        return res;
    }
};