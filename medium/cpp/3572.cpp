// https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/description/

class Solution
{
public:
    int maxSumDistinctTriplet(const std::vector<int>& x, const std::vector<int>& y)
    {
        std::unordered_map<int, int> maxVal;

        for (auto i = 0; i < std::size(x); i++)
        {
            if (const auto it = maxVal.find(x[i]); it != std::end(maxVal))
            {
                it->second = std::max(it->second, y[i]);
            }
            else
            {
                maxVal.emplace(x[i], y[i]);
            }
        }

        if (std::size(maxVal) < 3)
        {
            return -1;
        }

        std::multiset<int> triplet;

        for (const auto [_, val] : maxVal)
        {
            triplet.insert(val);

            if (std::size(triplet) > 3)
            {
                triplet.erase(std::begin(triplet));
            }
        }

        return std::accumulate(std::cbegin(triplet), std::cend(triplet), 0);
    }
};