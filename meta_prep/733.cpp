class Solution
{
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
        int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
        {
            return image;
        }

        const auto original_color = image[sr][sc];

        std::array<int, 4> dr{0, -1, 0, 1};
        std::array<int, 4> dc{-1, 0, 1, 0};

        std::queue<std::pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        const auto n = std::size(image);
        const auto m = std::size(image.front());

        while (!q.empty())
        {
            const auto [r, c] = q.front();
            q.pop();

            for (auto d = 0; d < 4; d++)
            {
                const auto next_r = r + dr[d];
                const auto next_c = c + dc[d];

                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m &&
                    image[next_r][next_c] == original_color)
                {
                    image[next_r][next_c] = color;
                    q.push({next_r, next_c});
                }
            }
        }

        return image;
    }
};