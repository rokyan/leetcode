// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

class Solution
{
public:
    std::string getHappyString(int n, int k)
    {
        std::string res;
        gen(0, n, k, res);

        return res;
    }

private:
    void gen(int pos, int n, int k, std::string& res, std::string acc = "")
    {
        if (cnt > k)
        {
            return;
        }

        if (pos == n)
        {
            cnt++;

            if (cnt == k)
            {
                res = acc;
            }

            return;
        }

        for (auto c = 'a'; c <= 'c'; c++)
        {
            if (acc.empty() || acc.back() != c)
            {
                acc.push_back(c);
                gen(pos + 1, n, k, res, acc);
                acc.pop_back();
            }
        }
    }

private:
    int cnt = 0;
};