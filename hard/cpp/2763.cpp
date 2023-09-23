// https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/description/

class Solution
{
public:
    int sumImbalanceNumbers(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<char> probe(n + 1);

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            std::fill(std::begin(probe), std::end(probe), false);
            probe[nums[i]] = true;

            auto cnt = 0;

            for (auto j = i + 1; j < n; j++)
            {
                const auto val = nums[j];
                
                if (probe[val])
                {
                    //
                }
                else if (val > 1 && probe[val - 1] && val < n && probe[val + 1])
                {
                    cnt--;
                }
                else if (val > 1 && probe[val - 1] || val < n && probe[val + 1])
                {
                    //
                }
                else
                {
                    cnt++;
                }

                probe[val] = true;

                res += cnt;
            }
        }

        return res;
    }
};