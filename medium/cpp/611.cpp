// https://leetcode.com/problems/valid-triangle-number/description/

class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));

        const auto n = static_cast<int>(std::size(nums));

        auto res = 0;

        for (auto i = 0; i + 2 < n; i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            
            auto j = i + 1;
            auto k = i + 2;

            while (j + 1 < n)
            {
                while (k < n && nums[i] + nums[j] > nums[k])
                {
                    k++;
                }

                res += k - j - 1;

                j++;
            }
        }

        return res;
    }
};