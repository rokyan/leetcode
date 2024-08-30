// https://leetcode.com/problems/maximum-array-hopping-score-i/description/

class Solution
{
public:
    int maxScore(std::vector<int>& nums) 
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> rm(n);
        rm[n - 1] = n - 1;

        for (auto i = n - 2; i >= 0; i--)
        {
            rm[i] = i;

            if (nums[i] < nums[rm[i + 1]])
            {
                rm[i] = rm[i + 1];
            }
        }

        auto pos = 0;
        auto res = 0LL;

        while (pos + 1 < n)
        {
            auto next_pos = rm[pos + 1];
            res += 1LL * (next_pos - pos) * nums[next_pos];
            pos = next_pos;
        }

        return res;    
    }
};