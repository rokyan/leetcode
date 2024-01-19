// https://leetcode.com/problems/longest-happy-string/

class Solution
{
public:
    std::string longestDiverseString(int a, int b, int c)
    {
        std::priority_queue<std::pair<int, char>> heap;
        if (a > 0) heap.push({ a, 'a' });
        if (b > 0) heap.push({ b, 'b' });
        if (c > 0) heap.push({ c, 'c' });

        std::string res;
        res.reserve(a + b + c);

        while (std::size(heap) > 1)
        {
            auto x = heap.top();
            heap.pop();
            auto y = heap.top();
            heap.pop();

            if (x.first > 1 && (res.empty() || res.back() != x.second))
            {
                x.first -= 2;
                res.push_back(x.second);
                res.push_back(x.second);
            }
            else
            {
                x.first--;
                res.push_back(x.second);
            }

            res.push_back(y.second);
            y.first--;

            if (x.first > 0)
            {
                heap.push(x);
            }

            if (y.first > 0)
            {
                heap.push(y);
            }
        }

        if (!heap.empty())
        {
            auto x = heap.top();
            heap.pop();

            if (x.first > 1 && (res.empty() || res.back() != x.second))
            {
                x.first -= 2;
                res.push_back(x.second);
                res.push_back(x.second);
            }
            else
            {
                x.first--;
                res.push_back(x.second);
            }
        }

        return res;
    }
};