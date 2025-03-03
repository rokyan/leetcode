class Solution
{
public:
    int getLargestOutlier(const std::vector<int>& nums)
    {
        std::vector<int> freq(2000 + 1);
        auto sum = 0;

        for (auto num : nums)
        {
            freq[num + 1000]++;
            sum += num;
        }

        std::optional<int> res;

        for (auto num : nums)
        {
            const auto rem = sum - num;

            if (rem % 2 == 0)
            {
                freq[num + 1000]--;

                if (rem / 2 >= -1000 && rem / 2 <= 1000 && freq[rem / 2 + 1000])
                {
                    res = res ? std::max(res.value(), num) : num;
                }

                freq[num + 1000]++;
            }
        }

        return res.value();
    }
};