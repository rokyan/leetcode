// https://leetcode.com/problems/maximum-number-of-eaten-apples/

class Solution
{
public:
    int eatenApples(std::vector<int>& apples, std::vector<int>& days)
    {
        const auto n = static_cast<int>(std::size(apples));

        std::priority_queue<std::pair<int, int>> heap;
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (apples[i] > 0)
            {
                heap.push({ -days[i] - i + 1, apples[i] });
            }

            while (!heap.empty() && -heap.top().first < i)
            {
                heap.pop();
            }

            if (!heap.empty())
            {
                auto top = heap.top();
                heap.pop();

                top.second--;
                res++;

                if (top.second > 0)
                {
                    heap.push(top);
                }
            }
        }

        auto last = n - 1;

        while (!heap.empty())
        {
            if (last < -heap.top().first)
            {
                res += std::min(-heap.top().first - last, heap.top().second);
                last = min(-heap.top().first, last + heap.top().second);
            }

            heap.pop();
        }

        return res;
    }
};