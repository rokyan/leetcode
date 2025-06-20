// https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/

class Solution
{
private:
    static constexpr auto maxVal = 2048;

public:
    int uniqueXorTriplets(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<char> seen(maxVal);
        std::vector<char> fin(maxVal);

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j <= i; j++)
            {
                seen[nums[i] ^ nums[j]] = true;
            }

            for (auto val = 0; val < maxVal; val++)
            {
                const auto t = val ^ nums[i];

                if (seen[t] && !fin[val])
                {
                    fin[val] = true;
                    res++;
                }
            }
        }

        return res;
    }
};