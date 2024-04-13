// https://leetcode.com/problems/3sum-with-multiplicity/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int threeSumMulti(std::vector<int>& arr, int target)
    {
        const auto n = std::size(arr);

        std::array<int, 101> freq;

        auto res = 0;

        for (auto i = 0; i + 2 < n; i++)
        {
            std::fill(std::begin(freq), std::end(freq), 0);

            for (auto k = i + 1; k < n; k++)
            {
                const auto val = target - arr[i] - arr[k];

                if (val >= 0 && val <= 100)
                {
                    res += freq[val];
                    res %= mod;
                }

                freq[arr[k]]++;
            }
        }

        return res;
    }
};