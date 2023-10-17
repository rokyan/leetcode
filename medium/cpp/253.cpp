// https://leetcode.com/problems/meeting-rooms-ii/description/

class Solution
{
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals)
    {
        std::map<int, int> cnt;

        for (auto&& interval : intervals)
        {
            cnt[interval[0]]++;
            cnt[interval[1]]--;
        }

        auto rs = 0;
        auto res = 0;

        for (auto&& entry : cnt)
        {
            rs += entry.second;
            res = std::max(res, rs);
        }

        return res;
    }
};