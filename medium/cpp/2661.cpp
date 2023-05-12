// https://leetcode.com/problems/first-completely-painted-row-or-column/description/

class Solution
{
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());

        std::vector<std::pair<int, int>> pos(n * m);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                pos[mat[i][j] - 1] = {i, j};
            }
        }

        std::vector<int> cntr(n, m);
        std::vector<int> cntc(m, n);

        auto res = 0;

        for (const auto e : arr)
        {           
            cntr[pos[e - 1].first]--;

            if (cntr[pos[e - 1].first] == 0)
            {
                return res;
            }

            cntc[pos[e - 1].second]--;

            if (cntc[pos[e - 1].second] == 0)
            {
                return res;
            }

            res++;
        }

        return res;
    }
};