// https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/description/

class Solution
{
public:
    long long maxProduct(std::vector<int>& nums)
    {
        const int n = std::size(nums);

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int num : nums)
        {
            pq.push(std::abs(num));

            if (pq.size() > 2)
            {
                pq.pop();
            }
        }

        long long res = 100000L;

        while (!pq.empty())
        {
            res *= pq.top();
            pq.pop();
        }

        return res;
    }
};