// https://leetcode.com/problems/find-the-longest-equal-subarray/description/

class Solution
{
public:
    int longestEqualSubarray(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, std::deque<int>> pos;

        auto res = 1;

        const auto n = std::size(nums);

        for (auto i = 0; i < n; i++)
        {
            if (auto it = pos.find(nums[i]); it != std::end(pos))
            {
                auto& ap = it->second;

                ap.push_back(i);

                while (ap.back() - ap.front() + 1 - std::size(ap) > k)
                {
                    ap.pop_front();
                }

                res = std::max<int>(res, std::size(ap));
            }
            else
            {
                pos[nums[i]].push_back(i);
            }
        }

        return res;
    }
};