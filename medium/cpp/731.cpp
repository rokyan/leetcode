// https://leetcode.com/problems/my-calendar-ii/description/

class MyCalendarTwo
{
public:
    MyCalendarTwo() = default;
    
    bool book(int startTime, int endTime)
    {
        cnt[startTime]++;
        cnt[endTime]--;

        auto booked = 0;

        for (const auto& [_, t] : cnt)
        {
            booked += t;

            if (booked >= 3)
            {
                cnt[startTime]--;
                cnt[endTime]++;
                return false;
            }
        }

        return true;
    }

private:
    std::map<int, int> cnt;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */