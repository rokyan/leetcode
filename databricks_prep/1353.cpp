class Solution
{
public:
    int maxEvents(std::vector<std::vector<int>>& events)
    {
        const auto comp = [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
        };

        std::sort(std::begin(events), std::end(events), comp);

        auto res = 0;

        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

        for (auto d = 1, p = 0; d <= 100000; d++)
        {
            while (p < std::size(events) && events[p][0] <= d)
            {
                heap.push(events[p++][1]);
            }

            while (!heap.empty() && heap.top() < d)
            {
                heap.pop();
            }

            if (!heap.empty())
            {
                res++;
                heap.pop();
            }
        }

        return res;
    }
};