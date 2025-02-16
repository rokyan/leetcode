class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
    {
        auto comp = [this](const auto& lhs, const auto& rhs) {
            return dist(lhs) < dist(rhs);
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> pq{comp};

        for (const auto& point : points)
        {
            pq.push(point);

            if (std::size(pq) > k)
            {
                pq.pop();
            }
        }

        std::vector<std::vector<int>> res;
        res.reserve(k);

        while (!pq.empty())
        {
            res.push_back(std::move(pq.top()));
            pq.pop();
        }

        return res;
    }

private:
    int sq(int x)
    {
        return x * x;
    }

    int dist(const std::vector<int>& point)
    {
        return sq(point[0]) + sq(point[1]);
    }
};