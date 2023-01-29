// https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

class Solution
{
public:
    long long maxKelements(std::vector<int>& nums, int k)
    {
        std::priority_queue<int> pq(std::begin(nums), std::end(nums));

        long long res = 0;

        while (k--)
        {
            const auto num = pq.top();
            pq.pop();

            res += num;

            pq.push(num / 3 + (num % 3 != 0));
        }

        return res;
    }
};