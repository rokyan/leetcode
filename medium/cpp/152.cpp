// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution
{
public:
    int maxProduct(std::vector<int>& nums)
    {
        std::optional<int> pos, neg;
        auto res = nums.front();

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (nums[i] > 0)
            {
                if (pos)
                {
                    pos = pos.value() * nums[i];
                }
                else
                {
                    pos = nums[i];
                }

                if (neg)
                {
                    neg = neg.value() * nums[i];
                }
            }
            else if (nums[i] < 0)
            {
                if (pos && neg)
                {
                    const auto val = pos.value();
                    pos = neg.value() * nums[i];
                    neg = val * nums[i];
                }
                else if (pos)
                {
                    neg = pos.value() * nums[i];
                    pos.reset();
                }
                else if (neg)
                {
                    pos = neg.value() * nums[i];
                    neg = nums[i];
                }
                else
                {
                    neg = nums[i];
                }
            }
            else
            {
                pos.reset();
                neg.reset();

                res = std::max(res, 0);
            }

            if (pos)
            {
                res = std::max(res, pos.value());
            }

            if (neg)
            {
                res = std::max(res, neg.value());
            }
        }

        return res;
    }
};