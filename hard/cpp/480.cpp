// https://leetcode.com/problems/sliding-window-median/description/

class Solution
{
public:
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::multiset<int> larger;
        std::multiset<int, greater<int>> smaller;

        const auto t = (k + 1) / 2;

        for (auto i = 0; i + 1 < k; i++)
        {
            larger.insert(nums[i]);

            if (std::size(larger) > t)
            {
                smaller.insert(*std::begin(larger));
                larger.erase(std::begin(larger));
            }
        }

        std::vector<double> res(n - k + 1);

        for (auto i = k - 1; i < n; i++)
        {
            larger.insert(nums[i]);

            smaller.insert(*std::begin(larger));
            larger.erase(std::begin(larger));

            while (std::size(larger) < t)
            {
                larger.insert(*std::begin(smaller));
                smaller.erase(std::begin(smaller));
            }

            res[i - k + 1] = (k % 2 == 1) ? *std::begin(larger) : (0.0 + *std::begin(larger) + *std::begin(smaller)) / 2.0;

            if (const auto it = larger.find(nums[i - k + 1]); it != std::end(larger))
            {
                larger.erase(it);
            }
            else
            {
                smaller.erase(smaller.find(nums[i - k + 1]));
            }
        }

        return res;
    }
};