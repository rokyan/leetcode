// https://leetcode.com/problems/interval-list-intersections/description/

class Solution
{
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList)
    {
        std::vector<std::vector<int>> res;

        for (auto i = 0, j = 0; i < std::size(firstList); i++)
        {
            while (j < std::size(secondList) && secondList[j][1] < firstList[i][0])
            {
                j++;
            }

            while (j < std::size(secondList))
            {
                const auto l = std::max(firstList[i][0], secondList[j][0]);
                const auto r = std::min(firstList[i][1], secondList[j][1]);

                if (l <= r)
                {
                    res.push_back({ l, r });
                }
                else
                {
                    break;
                }

                j++;
            }

            j = std::max(j - 1, 0);
        }

        return res;
    }
};