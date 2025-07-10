// https://leetcode.com/problems/smallest-subarray-to-sort-in-every-sliding-window/description/

class Solution
{
public:
    std::vector<int> minSubarraySort(const std::vector<int>& nums, int k)
    {
        const int n = std::size(nums);

        std::vector<int> res(n - k + 1);

        std::multiset<int> sorted;

        for (int i = 0; i < n; i++)
        {
            sorted.insert(nums[i]);

            if (i >= k - 1)
            {
                auto l = 0;
                auto leftIter = std::cbegin(sorted);

                while (l < k && nums[i - k + 1 + l] == *leftIter)
                {
                    l++;
                    leftIter++;
                }

                if (l < k)
                {
                    auto r = k - 1;
                    auto rightIter = std::crbegin(sorted);

                    while (r >= 0 && nums[i - k + 1 + r] == *rightIter)
                    {
                        r--;
                        rightIter++;
                    }

                    res[i - k + 1] = r - l + 1;
                }

                sorted.erase(sorted.find(nums[i - k + 1]));
            }
        }

        return res;
    }
};