// https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/description/

class Solution
{
public:
    std::vector<long long> unmarkedSumArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries)
    {
        auto sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0LL);

        const auto n = std::size(nums);

        std::vector<std::pair<int, int>> v(n);

        for (auto i = 0; i < n; i++)
        {
            v[i] = { nums[i], i };
        }

        std::sort(std::begin(v), std::end(v));

        std::vector<int> idx(n);

        for (auto i = 0; i < n; i++)
        {
            idx[v[i].second] = i;
        }

        std::vector<long long> res;
        res.reserve(std::size(queries));

        std::vector<char> marked(n);

        int rem = n;
        auto last = 0;

        for (const auto& q : queries)
        {
            if (!marked[idx[q[0]]])
            {
                sum -= nums[q[0]];
                marked[idx[q[0]]] = true;
                rem--;
            }

            for (auto i = 0; i < q[1] && rem; i++)
            {
                while (marked[last])
                {
                    last++;
                }

                rem--;
                marked[last] = true;
                sum -= v[last].first;
            }

            res.push_back(sum);
        }

        return res;
    }
};