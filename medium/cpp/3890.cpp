// https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/description/

class Solution
{
public:
    std::vector<int> findGoodIntegers(int n)
    {
        int x = 1;

        while (cubify(x) <= n)
        {
            x++;
        }

        std::unordered_map<int, int> unSums;

        std::vector<int> res;

        for (int a = 1; a < x; a++)
        {
            for (int b = a; b < x; b++)
            {
                const long long sum = 0LL + cubify(a) + cubify(b);

                if (sum > n)
                {
                    break;
                }

                if (unSums[sum]++ == 1)
                {
                    res.push_back(sum);
                }
            }
        }

        std::ranges::sort(res);

        return res;
    }

private:
    static int cubify(int x)
    {
        return x * x * x;
    }
};