// https://leetcode.com/problems/employee-free-time/description/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution
{
public:
    std::vector<Interval> employeeFreeTime(std::vector<std::vector<Interval>> schedule)
    {
        std::map<int, int> cnt;

        for (auto&& s : schedule)
        {
          for (auto&& e : s)
          {
            cnt[e.start]++;
            cnt[e.end]--;
          }
        }

        std::vector<Interval> all;
        auto prev = -1;
        auto balance = 0;

        for (auto&& e : cnt)
        {
          balance += e.second;

          if (balance == 0)
          {
            prev = e.first;
          }
          else if (prev != -1)
          {
            all.emplace_back(prev, e.first);
            prev = -1;
          }
        }

        return all;
    }
};