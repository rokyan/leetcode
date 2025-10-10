class RecentCounter
{
public:
    RecentCounter() = default;
    
    int ping(int t)
    {
        data.push_back(t);

        while (data.back() - data.front() > 3000)
        {
            data.pop_front();
        }

        return std::size(data);
    }

private:
    std::deque<int> data;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */