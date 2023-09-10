class Solution
{
private:
    using pii = std::pair<int, int>;

public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> counter;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

        for (auto num : nums)
        {
            counter[num]++;
        }

        for (auto&& entry : counter)
        {
            const auto value = entry.first;
            const auto count = entry.second;

            pq.push({ count, value });

            if (std::size(pq) > k)
            {
                pq.pop();
            }
        }

        std::vector<int> res;
        res.reserve(k);

        while (!pq.empty())
        {
            const auto& entry = pq.top();
            res.push_back(entry.second);
            pq.pop();
        }

        return res;
    }
};