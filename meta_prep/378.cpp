class Solution
{
private:
    struct state
    {
        state(int value, int row, int col)
            : value{value}
            , row{row}
            , col{col}
        {}

        bool operator<(const state& other) const noexcept
        {
            return value > other.value;
        }

        int value;
        int row;
        int col;
    };

public:
    int kthSmallest(const std::vector<std::vector<int>>& matrix, int k)
    {
        const auto n = static_cast<int>(std::size(matrix));

        std::priority_queue<state> pq;

        for (auto row = 0; row < std::min(k, n); row++)
        {
            pq.push({matrix[row][0], row, 0});
        }

        while (k-- > 1)
        {
            const auto s = pq.top();
            pq.pop();

            if (s.col + 1 < n)
            {
                pq.push({matrix[s.row][s.col + 1], s.row, s.col + 1});
            }
        }

        return pq.top().value;
    }
};