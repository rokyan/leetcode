// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

class Solution
{
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend)
    {
        const auto n = static_cast<int>(std::size(times));

        std::map<int, std::vector<int>> events;

        for (auto i = 0; i < n; i++)
        {
            events[times[i][0]].push_back(i + 1);
            events[times[i][1]].push_back(-i - 1);
        }

        std::set<int> free_seats;

        for (auto i = 0; i < n; i++)
        {
            free_seats.insert(i);
        }

        auto res = -1;

        std::unordered_map<int, int> seats;

        for (auto& entry : events)
        {
            std::sort(std::begin(entry.second), std::end(entry.second));

            for (auto id : entry.second)
            {
                if (id < 0)
                {
                    free_seats.insert(seats[-id]);
                    seats.erase(-id);
                }
                else
                {
                    const auto seat = *std::cbegin(free_seats);
                    free_seats.erase(std::cbegin(free_seats));

                    if (id == targetFriend + 1)
                    {
                        res = seat;
                        break;
                    }

                    seats[id] = seat;
                }
            }
        }

        return res;
    }
};