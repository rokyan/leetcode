// https://leetcode.com/problems/maximum-product-after-k-increments/description/

class Solution
{
public:
    int maximumProduct(std::vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<>> q(std::begin(nums), std::end(nums));

        while (k--)
        {
            const auto num = q.top();
            q.pop();
            q.push(num + 1);
        }

        constexpr auto mod = 1000 * 1000 * 1000 + 7;

        auto res = 1LL;

        while (!q.empty())
        {
            const auto num = q.top();
            q.pop();
            res *= num;
            res %= mod;
        }

        return res;
    }
};