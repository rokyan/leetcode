// https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

class Solution
{
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        auto cnt1 = get_counts(nums1);
        auto cnt2 = get_counts(nums2);

        auto ans = 0;

        for (auto bit = 0; bit < 32; bit++)
        {
            if ((cnt1[0][bit] * cnt2[1][bit] + cnt1[1][bit] * cnt2[0][bit]) & 1)
            {
                ans |= (1 << bit);
            }
        }

        return ans;
    }

private:
    std::vector<std::vector<int>> get_counts(const std::vector<int>& nums)
    {
        std::vector<std::vector<int>> cnt(2, std::vector<int>(32));

        for (auto pos = 0; pos < std::size(nums); pos++)
        {
            for (auto bit = 0; bit < 32; bit++)
            {
                cnt[(nums[pos] & (1 << bit)) != 0][bit]++;
            }
        }

        return cnt;
    }
};