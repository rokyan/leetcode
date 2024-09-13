// https://leetcode.com/problems/sum-of-beauty-in-the-array/description/

class Solution
{
public:
    int sumOfBeauties(const std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<char> score(n, 0);

        for (auto i = 1, max_so_far = nums[0]; i + 1 < n; i++)
        {
            if (max_so_far < nums[i])
            {
                score[i] = 2;
            }

            max_so_far = std::max(max_so_far, nums[i]);
        }

        for (auto i = n - 2, min_so_far = nums[n - 1]; i >= 0; i--)
        {
            if (min_so_far <= nums[i])
            {
                score[i] = 0;
            }

            min_so_far = std::min(min_so_far, nums[i]);
        }

        for (auto i = 1; i + 1 < n; i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1] && score[i] == 0)
            {
                score[i] = 1;
            }
        }

        return std::accumulate(std::cbegin(score), std::cend(score), 0);
    }
};