// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/

class Solution
{
public:
    std::vector<int> countRectangles(std::vector<std::vector<int>>& rectangles, std::vector<std::vector<int>>& points)
    {
        std::vector<int> line(105);

        for (auto&& r : rectangles)
        {
            line[0]++;
            line[r[1] + 1]--;
        }

        for (auto i = 1; i < 105; i++)
        {
            line[i] += line[i - 1];
        }

        std::sort(std::begin(rectangles), std::end(rectangles));

        std::vector<std::pair<std::vector<int>, int>> pwp(std::size(points));

        for (auto i = 0; i < std::size(points); i++)
        {
            pwp[i] = std::make_pair(points[i], i);
        }

        std::sort(std::begin(pwp), std::end(pwp));

        auto rp = 0;

        std::vector<int> res(std::size(points));

        for (auto i = 0; i < std::size(pwp); i++)
        {
            while (rp < std::size(rectangles) && rectangles[rp][0] < pwp[i].first[0])
            {
                for (auto j = 0; j <= rectangles[rp][1]; j++)
                {
                    line[j]--;
                }

                rp++;
            }

            res[pwp[i].second] = line[pwp[i].first[1]];
        }

        return res;
    }
};