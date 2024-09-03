// https://leetcode.com/problems/k-th-nearest-obstacle-queries/description/

class Solution
{
public:
    std::vector<int> resultsArray(const std::vector<std::vector<int>>& queries, int k)
    {
        std::priority_queue<int> pq;

        std::vector<int> res(std::size(queries));

        for (auto i = 0; i < std::size(queries); i++)
        {
            const auto& q = queries[i];

            pq.push(std::abs(q[0]) + std::abs(q[1]));

            if (std::size(pq) > k)
            {
                pq.pop();
            }

            res[i] = std::size(pq) < k ? -1 : pq.top();
        }

        return res;
    }
};