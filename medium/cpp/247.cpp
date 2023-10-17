// https://leetcode.com/problems/strobogrammatic-number-ii/description/

class Solution
{
public:
    std::vector<std::string> findStrobogrammatic(int n)
    {
        std::vector<std::string> all;
        gen(0, n / 2, "", all);

        std::vector<std::string> res;

        for (auto& s : all)
        {
            auto suffix = s;

            for (auto& c : suffix)
            {
                if (c == '6')
                {
                    c = '9';
                }
                else if (c == '9')
                {
                    c = '6';
                }
            }

            std::reverse(std::begin(suffix), std::end(suffix));

            if (n & 1)
            {
                res.push_back(s + "0" + suffix);
                res.push_back(s + "1" + suffix);
                res.push_back(s + "8" + suffix);
            }
            else
            {
                res.push_back(s + suffix);
            }
        }

        return res;
    }

private:
    void gen(int p, int n, std::string acc, std::vector<std::string>& all)
    {
        if (p == n)
        {
            all.push_back(acc);
            return;
        }

        if (p > 0)
        {
            acc.push_back('0');
            gen(p + 1, n, acc, all);
            acc.pop_back();
        }

        acc.push_back('1');
        gen(p + 1, n, acc, all);
        acc.pop_back();

        acc.push_back('6');
        gen(p + 1, n, acc, all);
        acc.pop_back();

        acc.push_back('8');
        gen(p + 1, n, acc, all);
        acc.pop_back();

        acc.push_back('9');
        gen(p + 1, n, acc, all);
        acc.pop_back();
    }
};