// https://leetcode.com/problems/once-twice/description/

class Solution
{
public:
    std::vector<int> onceTwice(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto diffBit = -1;

        for (auto bit = 0; bit < 32; bit++)
        {
            auto cnt = 0;

            for (auto num : nums)
            {
                if (num & (1 << bit))
                {
                    cnt++;
                }
            }

            const auto md = cnt % 3;

            if (md != 0)
            {
                diffBit = bit;
                break;
            }
        }

        std::vector<int> res(2);

        for (auto bit = 0; bit < 32; bit++)
        {
            auto cnt1 = 0;
            auto cnt2 = 0;

            for (auto num : nums)
            {
                if (num & (1 << diffBit))
                {
                    if (num & (1 << bit))
                    {
                        cnt1++;
                    }
                }
                else
                {
                    if (num & (1 << bit))
                    {
                        cnt2++;
                    }
                }
            }

            if (cnt1 % 3 != 0)
            {
                res[0] |= 1 << bit;
            }

            if (cnt2 % 3 != 0)
            {
                res[1] |= 1 << bit;
            }
        }

        auto cnt = 0;

        for (auto num : nums)
        {
            if (res[0] == num)
            {
                cnt++;
            }

            if (cnt == 2)
            {
                std::swap(res[0], res[1]);
                break;
            }
        }

        return res;
    }
};