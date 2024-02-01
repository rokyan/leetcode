// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution
{
public:
    int numberOfSubarrays(std::vector<int>& nums, int k)
    {
        auto res = 0;

        for (auto l = -1, prev = -1, r = 0, cnt = 0; r < std::size(nums); r++)
        {
            if (nums[r] % 2 == 1)
            {
                if (l == -1)
                {
                    l = r;
                }

                cnt++;

                if (cnt == k + 1)
                {
                    prev = l;
                    l++;

                    while (l < r && nums[l] % 2 == 0)
                    {
                        l++;
                    }

                    cnt--;
                }
            }

            if (cnt == k)
            {
                res += l - prev;
            }
        }

        return res;
    }
};