// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/

class Solution
{
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum)
    {
        std::sort(std::begin(banned), std::end(banned));

        auto res = 0;

        for (auto i = 1, p = 0, sum = 0; i <= n && sum + i <= maxSum; i++)
        {
            while (p < std::size(banned) && banned[p] < i)
            {
                p++;
            }

            if (p < std::size(banned) && banned[p] == i)
            {
                continue;
            }

            res++;
            sum += i;
        }

        return res;
    }
};