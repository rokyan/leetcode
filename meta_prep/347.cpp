class Solution
{
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq;

        std::for_each(std::cbegin(nums), std::end(nums), [&freq](auto num) {
            freq[num]++;
        });

        auto comp = [&freq](auto x, auto y) {
            return freq[x] > freq[y];
        };

        std::priority_queue<int, std::vector<int>, decltype(comp)> pq{comp};

        for (auto [key, _] : freq)
        {
            pq.push(key);

            if (std::size(pq) > k)
            {
                pq.pop();
            }
        }

        std::vector<int> res;
        res.reserve(k);

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};