// https://leetcode.com/problems/number-of-subsequences-with-odd-sum/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int subsequenceCount(std::vector<int>& nums)
    {
        auto odd = 0;
        auto even = 0;

        for (auto i = 0; i < std::size(nums); i++)
        {
            auto n_odd = odd;
            auto n_even = even;

            if (nums[i] & 1)
            {
                n_odd += 1 + even;
                n_odd %= mod;

                n_even += odd;
                n_even %= mod;
            }
            else
            {
                n_odd += odd;
                n_odd %= mod;

                n_even += 1 + even;
                n_even %= mod;
            }

            odd = n_odd;
            even = n_even;
        }

        return odd;
    }
};