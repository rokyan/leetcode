// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/

class Solution
{
public:
    int minimumIndex(vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, int> freq;

        for (auto num : nums)
        {
            freq[num]++;
        }

        auto val = -1;
        auto cnt = -1;

        for (const auto& e : freq)
        {
            if (2 * e.second > n)
            {
                val = e.first;
                cnt = e.second;
                break;
            }
        }

        auto t = 0;

        for (auto i = 0 ; i < n - 1; i++)
        {
            if (nums[i] == val)
            {
                t++;
                cnt--;
            }

            if (2 * t > i + 1 && 2 * cnt > (n - i - 1))
            {
                return i;
            }
        }

        return -1;
    }
};