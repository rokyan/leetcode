// https://leetcode.com/problems/minimum-cost-to-make-arrays-identical/description/

class Solution
{
public:
    long long minCost(std::vector<int>& arr, std::vector<int>& brr, long long k)
    {
        const auto n = std::size(arr);

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            res += std::abs(arr[i] - brr[i]);
        }

        auto upd = k;

        std::ranges::sort(arr);
        std::ranges::sort(brr);

        for (auto i = 0; i < n; i++)
        {
            upd += std::abs(arr[i] - brr[i]);
        }

        res = std::min(res, upd);

        return res;
    }
};