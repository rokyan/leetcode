class Solution
{
public:
    double findMaxAverage(const std::vector<int>& nums, int k)
    {
        auto sum = 0;

        for (auto i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        auto res = (sum + .0) / k;

        for (auto i = k; i < std::size(nums); i++)
        {
            sum += nums[i];
            sum -= nums[i - k];
            res = std::max(res, (sum + .0) / k);
        }

        return res;
    }
};