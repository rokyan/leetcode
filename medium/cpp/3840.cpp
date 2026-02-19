// https://leetcode.com/problems/house-robber-v/description/

class Solution
{
public:
    long long rob(const std::vector<int>& nums, const std::vector<int>& colors)
    {
        const int n = nums.size();

        std::array<long long, 2> prev;
        prev.fill(0);

        for (int i = 0; i < n; i++)
        {
            const long long cur = std::max(
                nums[i] + (i > 0 && colors[i] != colors[i - 1] ? prev[1] : 0),
                nums[i] + prev[0]);

            prev[0] = std::max(prev[0], prev[1]);
            prev[1] = std::max(prev[1], cur);
        }

        return *std::max_element(prev.cbegin(), prev.cend());
    }
};