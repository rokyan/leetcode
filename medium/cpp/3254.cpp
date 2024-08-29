// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/

class Solution
{
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> res(n - k + 1, -1);

        for (auto i = 0; i + k - 1 < n; i++)
        {
            if (is_sorted(std::begin(nums) + i, std::begin(nums) + i + k) &&
                nums[i + k - 1] == nums[i] + k - 1)
            {
                res[i] = nums[i + k - 1];
            }
        }

        return res;
    }

private:
    template<typename It>
    bool is_sorted(It first, It last)
    {
        while (first < last)
        {
            auto next = first;
            ++next;

            if (next == last)
            {
                break;
            }

            if (*first >= *next)
            {
                return false;
            }

            first = next;
        }

        return true;
    }
};