// https://leetcode.com/problems/my-calendar-i/description/

class MyCalendar
{
public:
    MyCalendar() = default;
    
    bool book(int startTime, int endTime)
    {
        const auto it = events.lower_bound(startTime);

        if (it != std::cend(events) && it->first < endTime)
        {
            return false;
        }

        if (it != std::cbegin(events))
        {
            auto prev = std::prev(it);

            if (prev->second > startTime)
            {
                return false;
            }
        }

        events[startTime] = endTime;
        return true;
    }

private:
    std::map<int, int> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */