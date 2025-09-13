// https://leetcode.com/problems/maximum-distance-in-arrays/description/

class Solution
{
public:
    int maxDistance(const std::vector<std::vector<int>>& arrays)
    {
        std::multiset<int> ends;

        for (const auto& arr : arrays)
        {
            ends.insert(arr.back());
        }

        auto res = 0;

        for (const auto& arr : arrays)
        {
            ends.erase(ends.find(arr.back()));
            res = std::max(res, *std::rbegin(ends) - arr.front());
            ends.insert(arr.back());
        }

        return res;
    }
};