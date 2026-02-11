// https://leetcode.com/problems/merge-adjacent-equal-elements/description/

class Solution
{
public:
    std::vector<long long> mergeAdjacent(const std::vector<int>& nums)
    {
        std::vector<long long> res;
        res.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            long long cur = nums[i];

            while (!res.empty() && res.back() == cur)
            {
                res.pop_back();
                cur *= 2;
            }

            res.push_back(cur);
        }

        return res;
    }
};