class Solution
{
public:
    void sortColors(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        auto i = 0;
        auto j = n - 1;

        for (auto k = 0; k <= j; )
        {
            if (nums[k] == 0)
            {
                std::swap(nums[i], nums[k]);
                i++;
                k++;
            }
            else if (nums[k] == 2)
            {
                std::swap(nums[j], nums[k]);
                j--;
            }
            else
            {
                k++;
            }
        }
    }
};