// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

class Solution
{
public:
    long long countSubarrays(std::vector<int>& nums, int k)
    {
        const auto val = *std::max_element(std::cbegin(nums), std::cend(nums));
        const auto n = std::size(nums);

        auto cnt = 0;
        auto res = 0LL;

        for (auto left = 0, right = 0; left < n; left++)
        {
            while (right < n && cnt < k)
            {
                if (nums[right] == val)
                {
                    cnt++;
                }

                right++;
            }

            if (cnt == k)
            {
                res += n - right + 1;
            }

            if (nums[left] == val)
            {
                cnt--;
            }

            if (cnt < k && right == n)
            {
                break;
            }
        }

        return res;
    }
};