class Solution
{
public:
    int pivotIndex(const std::vector<int>& nums)
    {
        auto sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0);
        auto sumToTheLeft = 0;

        for (auto i = 0; i < std::size(nums); i++)
        {
            sum -= nums[i];

            if (sumToTheLeft == sum)
            {
                return i;
            }

            sumToTheLeft += nums[i];
        }

        return -1;
    }
};