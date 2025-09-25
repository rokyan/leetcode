// https://leetcode.com/problems/my-calendar-iii/description/

class MyCalendarThree
{
public:
    MyCalendarThree() = default;
    
    int book(int startTime, int endTime)
    {
        cnt[startTime]++;
        cnt[endTime]--;

        auto booked = 0;
        auto res = 0;

        for (const auto& [_, t] : cnt)
        {
            booked += t;
            res = std::max(res, booked);
        }

        return res;
    }

private:
    std::map<int, int> cnt;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */