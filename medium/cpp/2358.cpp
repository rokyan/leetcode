// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/

class Solution
{
public:
    int maximumGroups(std::vector<int>& grades)
    {
        auto num = 1;

        while ((num + 2) * (num + 1) / 2 <= std::size(grades))
        {
            num++;
        }

        return num;
    }
};