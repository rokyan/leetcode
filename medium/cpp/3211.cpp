// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

class Solution
{
public:
    std::vector<std::string> validStrings(int n)
    {
        std::vector<std::string> res;
        std::string acc;

        gen(n, acc, res);

        return res;
    }

private:
    void gen(int n, std::string acc, std::vector<std::string>& res)
    {
        if (std::size(acc) == n)
        {
            res.push_back(acc);
            return;
        }

        if (acc.empty())
        {
            acc.push_back('0');
            gen(n, acc, res);
            acc.back() = '1';
            gen(n, acc, res);
            acc.pop_back();
        }
        else
        {
            if (acc.back() == '1')
            {
                acc.push_back('0');
                gen(n, acc, res);
                acc.pop_back();
            }

            acc.push_back('1');
            gen(n, acc, res);
            acc.pop_back();
        }
    }
};