class Solution
{
public:
    int findKthLargest(const std::vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (auto num : nums)
        {
            pq.push(num);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};