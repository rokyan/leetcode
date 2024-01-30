// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/

class Solution
{
public:
    int kthSmallest(std::vector<std::vector<int>>& mat, int k)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());

        std::priority_queue<std::pair<int, std::vector<int>>> heap;

        auto s = 0;

        for (auto i = 0; i < n; i++)
        {
            s += mat[i][0];
        }

        heap.push({ -s, std::vector<int>(n, 0) });

        std::set<std::vector<int>> seen;

        while (--k)
        {
            auto [s, mask] = heap.top();
            heap.pop();

            s *= -1;

            for (auto i = 0; i < n; i++)
            {
                if (mask[i] + 1 < m)
                {
                    s -= mat[i][mask[i]];
                    mask[i]++;
                    s += mat[i][mask[i]];

                    if (seen.insert(mask).second)
                    {
                        heap.push({ -s, mask });
                    }

                    s -= mat[i][mask[i]];
                    mask[i]--;
                    s += mat[i][mask[i]];
                }
            }
        }

        return -heap.top().first;
    }
};