// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
    {
        std::vector<int> d(n, inf);
        d[src] = 0;

        k++;

        while (k--)
        {
            std::vector<int> temp_d(d);

            for (const auto& flight : flights)
            {
                if (d[flight[0]] != inf && temp_d[flight[1]] > d[flight[0]] + flight[2])
                {
                    temp_d[flight[1]] = d[flight[0]] + flight[2];
                }
            }

            d = std::move(temp_d);
        }

        for (auto v = 0; v < n; v++)
        {
            std::cout << d[v] << " ";
        }

        return d[dst] == inf ? -1 : d[dst];
    }
};