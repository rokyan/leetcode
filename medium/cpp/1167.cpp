// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution
{
public:
    int connectSticks(std::vector<int>& sticks)
    {
        std::priority_queue<int, std::vector<int>, std::greater<>> heap(std::begin(sticks), std::end(sticks));

        auto res = 0;

        while (std::size(heap) > 1)
        {
            const auto first = heap.top();
            heap.pop();

            const auto second = heap.top();
            heap.pop();

            heap.push(first + second);
            res += first + second;
        }

        return res;
    }
};