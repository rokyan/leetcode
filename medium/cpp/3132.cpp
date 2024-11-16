// https://leetcode.com/problems/find-the-integer-added-to-array-ii/description/

class Solution
{
public:
    int minimumAddedInteger(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::sort(std::begin(nums1), std::end(nums1));
        std::sort(std::begin(nums2), std::end(nums2));

        std::optional<int> res;

        for (auto i = 0; i + 1 < std::size(nums1); i++)
        {
            for (auto j = i + 1; j < std::size(nums1); j++)
            {
                auto d = 0;
                auto valid = true;

                for (auto k = 0; k < std::size(nums1) && valid; k++)
                {
                    if (k != i && k != j)
                    {
                        auto pos = k - (k > i) - (k > j);

                        if (pos == 0)
                        {
                            d = nums2[pos] - nums1[k];

                            if (res.has_value() && res.value() < d)
                            {
                                valid = false;
                                break;
                            }
                        }
                        else
                        {
                            valid &= d == (nums2[pos] - nums1[k]);
                        }
                    }
                }

                if (valid)
                {
                    res = res.has_value() ? std::min(res.value(), d) : d;
                }
            }
        }

        return res.value();
    }
};