class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        for (auto i = 0, j = 0; j < std::size(nums); j++)
        {
            if (nums[j] == 0)
            {
                continue;
            }

            std::swap(nums[i], nums[j]);
            i++;
        }
    }
};