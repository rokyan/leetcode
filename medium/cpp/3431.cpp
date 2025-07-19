// https://leetcode.com/problems/minimum-unlocked-indices-to-sort-nums/description/

class Solution
{
public:
    int minUnlockedIndices(std::vector<int>& nums, std::vector<int>& locked)
    {
        const int n = std::size(nums);

        auto seenOne = false;

        for (auto i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 1)
            {
                seenOne = true;
            }

            if (nums[i] == 3 && seenOne)
            {
                return -1;
            }
        }

        std::array<int, 2> vals{3, 2};
        auto s = 0;
        auto res = 0;

        for (auto val : vals)
        {
            auto pos = n - 1 - s;
            auto last = pos - 1;

            for (auto i = n - 1; i >= 0; i--)
            {
                if (nums[i] == val)
                {
                    s++;

                    for (auto j = i; j <= last; j++)
                    {
                        if (locked[j])
                        {
                            locked[j] = false;
                            res++;
                        }
                    }

                    std::swap(nums[i], nums[pos--]);
                    last = std::min(last, std::min(i - 1, pos - 1));
                }
            }
        }

        return res;
    }
};