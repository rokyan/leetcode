// https://leetcode.com/problems/movement-of-robots/description/

class Solution
{
public:
    int sumDistance(std::vector<int>& nums, std::string s, int d)
    {
        const auto n = std::size(nums);

        std::vector<long long> pos(n);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                pos[i] = nums[i] + d;
            }
            else
            {
                pos[i] = nums[i] - d;
            }
        }

        std::sort(std::begin(pos), std::end(pos));

        auto res = 0LL;
        auto ps = 0LL;

        for (auto i = 1; i < n; i++)
        {
            ps += (pos[i] - pos[i - 1]) * i;
            res += ps;
            res %= 1000000007;
        }

        return res;
    }
};