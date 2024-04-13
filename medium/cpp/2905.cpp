// https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/description/

class Solution
{
public:
    std::vector<int> findIndices(std::vector<int>& nums, int indexDifference, int valueDifference)
    {
        const auto n = std::size(nums);

        std::multiset<std::pair<int, int>> pref, suff;

        for (auto i = indexDifference; i < n; i++)
        {
            suff.insert({ nums[i], i });
        }

        for (auto i = 0; i + indexDifference < std::size(nums); i++)
        {
            pref.insert({ nums[i], i });

            if (std::abs(std::begin(pref)->first - std::rbegin(suff)->first) >= valueDifference)
            {
                return { std::begin(pref)->second, std::rbegin(suff)->second };
            }

            if (std::abs(std::rbegin(pref)->first - std::begin(suff)->first) >= valueDifference)
            {
                return { std::rbegin(pref)->second, std::begin(suff)->second };
            }

            suff.erase(suff.find({ nums[i + indexDifference], i + indexDifference }));
        }

        return { -1, -1 };
    }
};