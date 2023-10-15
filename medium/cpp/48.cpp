// https://leetcode.com/problems/rotate-image/description/

class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        const auto n = std::size(matrix);

        auto d = n;
        auto s = 0;

        while (d > 1)
        {
            for (auto k = 0; k + 1 < d; k++)
            {
                swap(matrix[s][s + k], matrix[s + k][s + d - 1], matrix[s + d - 1][s + d - 1 - k], matrix[s + d - 1 - k][s]);
            }

            s++;

            d -= 2;
        }
    }

private:
    void swap(int& e1, int& e2, int& e3, int& e4)
    {
        // std::cout << e1 << " " << e2 << " " << e3 << " " << e4 << std::endl;
        const auto t = e4;
        e4 = e3;
        e3 = e2;
        e2 = e1;
        e1 = t;
    }
};