// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/

class Solution
{
public:
    int minElements(const std::vector<int>& nums, int limit, int goal)
    {
        long long sum = std::accumulate(nums.cbegin(), nums.cend(), 0LL);
        long long diff = std::abs(goal - sum);
        return (diff + limit - 1) / limit;
    }
};