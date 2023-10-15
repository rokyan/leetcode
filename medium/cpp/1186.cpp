// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

class Solution
{
public:
    int maximumSum(std::vector<int>& arr)
    {
        const auto n = std::size(arr);

        std::vector<int> pre(n);
        pre[0] = arr[0];

        for (auto i = 1; i < n; i++)
        {
            pre[i] = arr[i] + std::max(0, pre[i - 1]);
        }

        std::vector<int> suf(n);
        suf[n - 1] = arr[n - 1];

        for (auto i = static_cast<int>(n) - 2; i >= 0; i--)
        {
            suf[i] = arr[i] + std::max(0, suf[i + 1]);
        }

        auto res = static_cast<int>(-1'100'100'100);

        for (auto i = 0; i < n; i++)
        {
            auto s = arr[i];

            if (i > 0 && pre[i - 1] > 0)
            {
                s += pre[i - 1];
            }

            if (i + 1 < n && suf[i + 1] > 0)
            {
                s += suf[i + 1];
            }

            res = std::max(res, s);

            if (i > 0)
            {
                s = pre[i - 1];

                if (i + 1 < n && suf[i + 1] > 0)
                {
                    s += suf[i + 1];
                }

                res = std::max(res, s);
            }

            if (i + 1 < n)
            {
                s = suf[i + 1];

                if (i > 0 && pre[i - 1] > 0)
                {
                    s += pre[i - 1];
                }

                res = std::max(res, s);
            }
        }

        return res;
    }
};