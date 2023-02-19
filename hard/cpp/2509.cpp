// https://leetcode.com/problems/cycle-length-queries-in-a-tree/description/

class Solution
{
public:
    std::vector<int> cycleLengthQueries(int n, std::vector<std::vector<int>>& queries)
    {
        std::vector<int> path_u(n), path_v(n);

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            auto u = query[0];
            auto v = query[1];

            auto len_u = calc(u, path_u);
            auto len_v = calc(v, path_v);

            auto pt_u = 0;
            auto pt_v = 0;

            while (pt_u < len_u && pt_v < len_v && path_u[pt_u] == path_v[pt_v])
            {
                pt_u++;
                pt_v++;
            }

            res.push_back(len_u - pt_u + len_v - pt_v + 1);
        }

        return res;
    }

private:
    int calc(int v, std::vector<int>& path)
    {
        auto len = 0;

        while (v)
        {
            path[len++] = v;
            v >>= 1;
        }

        std::reverse(std::begin(path), std::begin(path) + len);

        return len;
    }
};