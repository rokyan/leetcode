// https://leetcode.com/problems/continuous-subarrays/description/

class Solution
{
public:
    long long continuousSubarrays(std::vector<int>& nums)
    {
        std::unordered_map<int, int> cnt;

        long long res = 0;

        for (auto l = 0, r = 0; r < std::size(nums); r++)
        {
            cnt[nums[r]]++;

            for (;;)
            {
                auto c = 0;

                for (auto d = -2; d <= 2; d++)
                {
                    if (const auto it = cnt.find(nums[r] + d); it != std::end(cnt))
                    {
                        c++;
                    }
                }

                if (c < std::size(cnt))
                {
                    cnt[nums[l]]--;

                    if (cnt[nums[l]] == 0)
                    {
                        cnt.erase(nums[l]);
                    }

                    l++;
                }
                else
                {
                    res += r - l + 1;
                    break;
                }
            }
        }

        return res;
    }
};