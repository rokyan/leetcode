// https://leetcode.com/problems/simplified-fractions/description/

class Solution
{
public:
    std::vector<std::string> simplifiedFractions(int n)
    {
        std::set<std::pair<int, int>> probe;

        for (auto den = 2; den <= n; den++)
        {
            for (auto num = 1; num < den; num++)
            {
                const auto g = gcd(num, den);

                probe.insert({ num / g, den / g });
            }
        }

        std::vector<std::string> res;
        res.reserve(std::size(probe));

        std::transform(std::cbegin(probe), std::cend(probe), std::back_inserter(res), [](const auto& e) {
            return std::to_string(e.first) + "/" + std::to_string(e.second);
        });

        return res;
    }

private:
    static int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};