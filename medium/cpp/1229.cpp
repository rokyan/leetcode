// https://leetcode.com/problems/meeting-scheduler/description/

class Solution
{
public:
    std::vector<int> minAvailableDuration(std::vector<std::vector<int>>& slots1,
        std::vector<std::vector<int>>& slots2, int duration)
    {
        std::sort(std::begin(slots1), std::end(slots1));
        std::sort(std::begin(slots2), std::end(slots2));

        std::vector<int> res;

        for (auto i = 0, j = 0; i < std::size(slots1) && j < std::size(slots2); )
        {
            if (slots1[i][1] < slots2[j][0])
            {
                i++;
            }
            else if (slots2[j][1] < slots1[i][0])
            {
                j++;
            }
            else
            {
                const auto start = std::max(slots1[i][0], slots2[j][0]);
                const auto end = std::min(slots1[i][1], slots2[j][1]);

                if (end - start >= duration)
                {
                    res = { start, start + duration };
                    break;
                }

                if (slots1[i][1] < slots2[j][1])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }

        return res;
    }
};