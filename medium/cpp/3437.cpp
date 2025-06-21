// https://leetcode.com/problems/permutations-iii/description/

class Solution
{
public:
    std::vector<std::vector<int>> permute(int n)
    {
        std::vector<char> used(n);
        std::vector<std::vector<int>> perm;
        std::vector<int> cur;

        gen(0, n, cur, used, perm);

        return perm;
    }

private:
    void gen(std::size_t pos, std::size_t n,
        std::vector<int>& cur,
        std::vector<char>& used,
        std::vector<std::vector<int>>& perm)
    {
        if (pos == n)
        {
            perm.push_back(cur);
        }
        else
        {
            for (auto d = 0; d < n; d++)
            {
                if (!used[d] && (pos == 0
                    || cur[pos - 1] % 2 == 0 && (d + 1) % 2 == 1
                    || cur[pos - 1] % 2 == 1 && (d + 1) % 2 == 0))
                {
                    used[d] = true;
                    cur.push_back(d + 1);
                    gen(pos + 1, n, cur, used, perm);
                    cur.pop_back();
                    used[d] = false;
                }
            }
        }
    }
};