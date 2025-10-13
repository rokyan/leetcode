class Solution
{
private:
    static constexpr int inf = 1000'000'007;

public:
    int findCheapestPrice(
        int n,
        const std::vector<std::vector<int>>& flights,
        int src,
        int dst,
        int k)
    {
        const int m = std::size(flights);

        std::vector<int> dist(n, inf);
        dist[src] = 0;
        std::vector<int> temp(dist);

        for (int times = 0; times <= k; times++)
        {
            for (const auto& flight : flights)
            {
                const int from = flight[0];
                const int to = flight[1];
                const int weight = flight[2];

                if (dist[from] != inf &&
                    temp[to] > dist[from] + weight)
                {
                    temp[to] = dist[from] + weight;
                }
            }

            dist = temp;
        }

        return dist[dst] == inf ? -1 : dist[dst];
    }
};