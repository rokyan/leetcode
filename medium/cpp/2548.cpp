// https://leetcode.com/problems/maximum-price-to-fill-a-bag/description/

class Solution
{
public:
    double maxPrice(std::vector<std::vector<int>>& items, int capacity)
    {
        std::sort(std::begin(items), std::end(items), [](const auto& left, const auto& right) {
            return static_cast<double>(left[0]) / left[1] > static_cast<double>(right[0]) / right[1];
        });

        auto res = 0.0;

        for (auto i = 0; i < std::size(items) && capacity; i++)
        {
            if (items[i][1] <= capacity)
            {
                capacity -= items[i][1];
                res += items[i][0];
            }
            else
            {
                res += capacity / static_cast<double>(items[i][1]) * items[i][0];
                capacity = 0;
            }
        }

        return capacity > 0 ? -1 : res;
    }
};