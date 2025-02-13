class Solution
{
public:
    std::vector<int> findBuildings(const std::vector<int>& heights)
    {
        const int n = std::size(heights);

        std::vector<int> res;
        res.reserve(n);

        for (auto i = n - 1, hsf = -1; i >= 0; i--)
        {
            if (heights[i] > hsf)
            {
                hsf = heights[i];
                res.push_back(i);
            }
        }

        std::reverse(std::begin(res), std::end(res));
        return res;
    }
};