// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/description/

class Solution
{
public:
    int smallestCommonElement(std::vector<std::vector<int>>& mat)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());

        std::vector<int> pos(n);

        for (;;)
        {
            auto max_val = mat[0][pos[0]];

            for (auto i = 1; i < n; i++)
            {
                max_val = std::max(max_val, mat[i][pos[i]]);
            }

            auto found = true;

            for (auto i = 1; i < n; i++)
            {
                while (pos[i] < m && mat[i][pos[i]] < max_val)
                {
                    pos[i]++;
                }

                if (pos[i] == m)
                {
                    return -1;
                }

                if (mat[i][pos[i]] > max_val)
                {
                    found = false;
                }
            }

            if (found)
            {
                return max_val;
            }
        }

        return -1;
    }
};