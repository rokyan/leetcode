// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder
{
public:
    MedianFinder()
        : total{ 0 }
    {        
    }
    
    void addNum(int num)
    {
        total++;

        if (upper.empty() || num >= upper.top())
        {
            upper.push(num);
        }
        else
        {
            lower.push(num);
        }

        if (std::size(upper) > (total + 1) / 2)
        {
            lower.push(upper.top());
            upper.pop();
        }
        else if (std::size(lower) > total / 2)
        {
            upper.push(lower.top());
            lower.pop();
        }
    }
    
    double findMedian()
    {
        if (total % 2)
        {
            return upper.top();
        }
        else
        {
            return (lower.top() + upper.top()) / 2.0;
        }
    }

private:
    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<>> upper;
    std::size_t total;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */