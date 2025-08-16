// https://leetcode.com/problems/maximum-increasing-triplet-value/description/

class Solution
{
public:
    int maximumTripletValue(const std::vector<int>& nums)
    {
        std::multiset<int> left, right(std::cbegin(nums), std::cend(nums));

        auto res = -1;

        for (auto i = 0; i + 1 < std::size(nums); i++)
        {
            right.erase(right.find(nums[i]));

            if (i > 0 && nums[i] < *std::rbegin(right))
            {
                auto it = left.lower_bound(nums[i]);

                if (it != std::cbegin(left))
                {
                    --it;

                    const auto value = *it + *std::rbegin(right) - nums[i];
                    res = res == -1 ? value : std::max(res, value);
                }
            }

            left.insert(nums[i]);
        }

        return res;
    }
};