// https://leetcode.com/problems/combinations/description/

class Solution
{
public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> comb(k);

        rec(0, 0, k, n, comb, res);

        return res;
    }

private:    
    void rec(int pos, int i, int k, int n, std::vector<int>& comb, std::vector<std::vector<int>>& res)
    {
        if (i == k)
        {
            res.push_back(comb);
        }
        else if (k - i <= n - pos)
        {
            rec(pos + 1, i, k, n, comb, res);
            comb[i] = pos + 1;
            rec(pos + 1, i + 1, k, n, comb, res);
        }
    }
};