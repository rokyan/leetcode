// https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/

class Solution
{
public:
    std::vector<int> distinctNumbers(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> cnt;

        for (auto i = 0; i < k; i++)
        {
            cnt[nums[i]]++;
        }

        std::vector<int> res;
        res.reserve(std::size(nums));

        for (auto i = k; i < std::size(nums); i++)
        {
            res.push_back(std::size(cnt));
            cnt[nums[i]]++;
            const auto it = cnt.find(nums[i - k]);
            if (it->second-- == 1)
            {
                cnt.erase(it);
            }
        }

        res.push_back(std::size(cnt));

        return res;
    }
};