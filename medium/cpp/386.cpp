// https://leetcode.com/problems/lexicographical-numbers/description/

class Solution
{
public:
    std::vector<int> lexicalOrder(int n)
    {
        std::vector<int> res;
        gen(0, n, res);
        return res;
    }

private:
    void gen(int cur, int n, std::vector<int>& res)
    {
        for (auto d = 0; d <= 9; d++)
        {
            if (d == 0 && cur == 0)
            {
                continue;
            }

            const auto next = 10 * cur + d;

            if (next <= n)
            {
                res.push_back(next);
                gen(next, n, res);
            }
        }
    }
};