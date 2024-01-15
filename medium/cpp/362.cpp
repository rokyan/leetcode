// https://leetcode.com/problems/design-hit-counter/

class HitCounter
{
public:
    HitCounter()
    {        
    }
    
    void hit(int timestamp)
    {
        ts.push_back(timestamp);
    }
    
    int getHits(int timestamp)
    {
        const auto start = std::max(0, timestamp - 299);
        const auto pos = std::distance(std::begin(ts), std::lower_bound(std::begin(ts), std::end(ts), start));
        return std::size(ts) - pos;
    }

private:
    std::vector<int> ts;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */