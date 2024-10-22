// https://leetcode.com/problems/find-if-array-can-be-sorted/description/

class Solution
{
public:
    bool canSortArray(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        for (auto i = 1; i < n; i++)
        {
            auto pos = i;

            while (pos > 0 && nums[pos] < nums[pos - 1] &&
                get_bits_num(nums[pos]) == get_bits_num(nums[pos - 1]))
            {
                std::swap(nums[pos], nums[pos - 1]);
                pos--;
            }

            if (pos > 0 && nums[pos] < nums[pos - 1])
            {
                return false;
            }
        }

        return true;
    }

private:
    int get_bits_num(int x)
    {
        auto cnt = 0;

        for (auto bit = 0; bit < 10; bit++)
        {
            if (x & (1 << bit))
            {
                cnt++;
            }
        }

        return cnt;
    }
};