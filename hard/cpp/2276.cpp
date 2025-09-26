// https://leetcode.com/problems/count-integers-in-intervals/description/

class CountIntervals
{
public:
    CountIntervals()
        : total{0}
    {}
    
    void add(int left, int right)
    {
        const auto it = intervals.lower_bound(left);

        if (it != std::cbegin(intervals))
        {
            auto jt = std::prev(it);

            if (jt->second >= left)
            {
                if (jt->second >= right)
                {
                    return;
                }

                total -= jt->second - jt->first + 1;
                left = std::min(left, jt->first);
                intervals.erase(jt);
            }
        }

        auto jt = it;

        while (jt != std::cend(intervals) && jt->first <= right)
        {
            total -= jt->second - jt->first + 1;
            right = std::max(right, jt->second);
            auto next = jt;
            next++;
            intervals.erase(jt);
            jt = next;
        }

        total += right - left + 1;
        intervals[left] = right;
    }
    
    int count()
    {
        return total;
    }

private:
    int total;
    std::map<int, int> intervals;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */