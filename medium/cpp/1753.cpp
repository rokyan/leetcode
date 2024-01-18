// https://leetcode.com/problems/maximum-score-from-removing-stones/description/

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        std::priority_queue<int> heap;
        heap.push(a);
        heap.push(b);
        heap.push(c);

        auto res = 0;

        while (std::size(heap) > 1)
        {
            const auto x = heap.top();
            heap.pop();

            const auto y = heap.top();
            heap.pop();

            res++;

            if (x > 1)
            {
                heap.push(x - 1);
            }

            if (y > 1)
            {
                heap.push(y - 1);
            }
        }

        return res;
    }
};