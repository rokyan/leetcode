class Solution
{
private:
    using mat_type = std::vector<std::vector<int>>;
    using comp_mat_type = std::vector<std::vector<std::pair<int, int>>>;

public:
    mat_type multiply(const mat_type& mat1, const mat_type& mat2)
    {
        const auto n = std::size(mat1);
        const auto m = std::size(mat2.front());

        mat_type res(n, std::vector<int>(m, 0));

        const auto cmat1 = compress(mat1);
        const auto cmat2 = compress(mat2);

        for (auto i = 0; i < n; i++)
        {
            for (const auto [p1, v1] : cmat1[i])
            {
                for (const auto [p2, v2] : cmat2[p1])
                {
                    res[i][p2] += v1 * v2;
                }
            }
        }

        return res;
    }

private:
    comp_mat_type compress(const mat_type& mat)
    {
        const auto n = std::size(mat);

        comp_mat_type res(n);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < std::size(mat[i]); j++)
            {
                if (mat[i][j] != 0)
                {
                    res[i].emplace_back(j, mat[i][j]);
                }
            }
        }

        return res;
    }

   
};