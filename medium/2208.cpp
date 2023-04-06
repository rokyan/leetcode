// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

class Solution
{
public:
    int halveArray(std::vector<int>& nums)
    {
        const auto sum = std::accumulate(std::begin(nums), std::end(nums), .0);

        std::priority_queue<double> pq(std::begin(nums), std::end(nums));

        auto rem_tot = .0;
        auto res = 0;

        while (rem_tot < sum / 2)
        {
            res++;

            const auto num = pq.top() / 2;
            pq.pop();

            rem_tot += num;
            pq.push(num);
        }

        return res;
    }
};