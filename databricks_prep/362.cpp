class HitCounter
{
public:
    HitCounter() = default;
    
    void hit(int timestamp)
    {
        if (data.empty() || data.back().first < timestamp)
        {
            data.push_back({timestamp, 1});
        }
        else
        {
            data.back().second++;
        }

        hitsCounter++;

        while (!data.empty() && data.front().first < timestamp - 299)
        {
            hitsCounter -= data.front().second;
            data.pop_front();
        }
    }
    
    int getHits(int timestamp)
    {
        const auto start = std::max(0, timestamp - 299);

        while (!data.empty() && data.front().first < start)
        {
            hitsCounter -= data.front().second;
            data.pop_front();
        }

        return hitsCounter;
    }

private:
    std::deque<std::pair<int, int>> data;
    int hitsCounter = 0;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */