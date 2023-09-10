// https://leetcode.com/problems/corporate-flight-bookings/description/

class Solution
{
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n)
    {
        std::vector<int> acc(n + 1);

        for (const auto& e : bookings)
        {
            acc[e[0] - 1] += e[2];
            acc[e[1]] -= e[2];
        }

        for (auto i = 1; i < n; i++)
        {
            acc[i] += acc[i - 1];
        }

        acc.pop_back();

        return acc;
    }
};