// https://leetcode.com/problems/maximum-team-size-with-overlapping-intervals/description/

class Solution
{
public:
    int maximumTeamSize(std::vector<int>& startTime, std::vector<int>& endTime)
    {
        const int n = startTime.size();

        std::vector<std::pair<int, int>> segments;
        segments.reserve(n);

        for (int i = 0; i < n; i++)
        {
            segments.emplace_back(startTime[i], endTime[i]);
        }

        std::ranges::sort(startTime);
        std::ranges::sort(endTime);

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int cur = n;

            const auto startTimeIt =
                std::upper_bound(startTime.begin(), startTime.end(), segments[i].second);

            if (startTimeIt != startTime.end())
            {
                cur -= startTime.end() - startTimeIt;
            }

            const auto endTimeIt =
                std::lower_bound(endTime.begin(), endTime.end(), segments[i].first);

            if (endTimeIt != endTime.begin())
            {
                cur -= endTimeIt - endTime.begin();
            }

            res = std::max(res, cur);
        }

        return res;
    }
};