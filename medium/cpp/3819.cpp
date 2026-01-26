// https://leetcode.com/problems/rotate-non-negative-elements/description/

class Solution
{
public:
    std::vector<int> rotateElements(std::vector<int>& nums, int k)
    {
        const int n = nums.size();

        std::vector<int> nonneg;
        nonneg.reserve(n);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                nonneg.push_back(nums[i]);
            }
        }

        if (nonneg.empty())
        {
            return nums;
        }

        k %= nonneg.size();

        if (k == 0)
        {
            return nums;
        }

        if (k > 0)
        {
            std::reverse(nonneg.begin(), nonneg.begin() + k);
            std::reverse(nonneg.begin() + k, nonneg.end());
            std::reverse(nonneg.begin(), nonneg.end());
        }

        for (int i = 0, j = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                nums[i] = nonneg[j++];
            }
        }

        return nums;
    }
};