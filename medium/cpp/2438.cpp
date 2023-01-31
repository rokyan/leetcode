// https://leetcode.com/problems/range-product-queries-of-powers/description/

class Solution
{
public:
    std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries)
    {
        auto pow = 1;

        while ((1 << pow) < n)
        {
            pow++;
        }

        std::vector<int> pows;

        while (n > 0)
        {
            if ((1 << pow) <= n)
            {
                pows.push_back(pow);
                n -= (1 << pow);
            }

            pow--;
        }

        std::reverse(std::begin(pows), std::end(pows));

        const auto pow_sum = std::accumulate(std::begin(pows), std::end(pows), 0);

        std::vector<int> prec(pow_sum + 1);
        prec[0] = 1;

        for (auto i = 1; i <= pow_sum; i++)
        {
            prec[i] = 2LL * prec[i - 1] % 1000000007;
        }

        for (auto i = 1; i < std::size(pows); i++)
        {
            pows[i] += pows[i - 1];
        }

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            const auto left = query[0];
            const auto right = query[1];

            auto cur = pows[right];

            if (left > 0)
            {
                cur -= pows[left - 1];
            }

            res.push_back(prec[cur]);
        }

        return res;
    }
};