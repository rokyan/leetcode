class Solution
{
private:
    using intervals_list = std::vector<std::vector<int>>;

public:
    intervals_list intervalIntersection(const intervals_list& firstList,
        const intervals_list& secondList)
    {
        intervals_list intersection;
        intersection.reserve(std::size(firstList));

        const auto n = std::size(firstList);
        const auto m = std::size(secondList);

        for (auto i = 0, j = 0; i < n && j < m; )
        {
            if (firstList[i][1] < secondList[j][0])
            {
                i++;
            }
            else if (secondList[j][1] < firstList[i][0])
            {
                j++;
            }
            else
            {
                intersection.push_back({
                    std::max(firstList[i][0], secondList[j][0]),
                    std::min(firstList[i][1], secondList[j][1])});

                if (firstList[i][1] <= secondList[j][1])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }

        return intersection;
    }
};