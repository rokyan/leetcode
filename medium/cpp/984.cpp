// https://leetcode.com/problems/string-without-aaa-or-bbb/

class Solution
{
public:
    std::string strWithout3a3b(int a, int b)
    {
       std::priority_queue<std::pair<int, char>> heap;
        if (a > 0) heap.push({ a, 'a' });
        if (b > 0) heap.push({ b, 'b' });

        std::string res;
        res.reserve(a + b);

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