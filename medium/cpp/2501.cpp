// https://leetcode.com/problems/longest-square-streak-in-an-array/description/

class Solution
{
public:
    int longestSquareStreak(std::vector<int>& nums)
    {
        std::unordered_set<int> probe(std::begin(nums), std::end(nums));

        auto max_num = *std::max_element(std::begin(nums), std::end(nums));

        auto ans = -1;

        for (auto num : nums)
        {
            auto len = 0;
            auto next = 1LL* num;

            while (true)
            {
                const auto it = probe.find(next);

                if (it == std::end(probe))
                {
                    break;
                }

                len++;

                if (next * next > max_num)
                {
                    break;
                }

                next *= next;
            }

            if (len > 1)
            {
                ans = std::max(ans, len);
            }
        }

        return ans;
    }
};