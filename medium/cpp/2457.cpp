// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/

class Solution
{
public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        auto digits = get_as_digits(n);

        const auto sum = std::accumulate(std::begin(digits), std::end(digits), 0);

        if (sum <= target)
        {
            return 0;
        }

        auto rem = sum - target + 1;
        auto car = 1;

        for (auto i = 0; i < std::size(digits); i++)
        {
            if (rem > 0)
            {
                rem -= digits[i];
                digits[i] = 0;
            }
            else
            {
                digits[i] += car;
                car = digits[i] / 10;
                digits[i] %= 10;
            }
        }

        if (car > 0)
        {
            digits.push_back(car);
        }

        return build(digits) - n;
    }

private:
    std::vector<int> get_as_digits(long long num)
    {
        std::vector<int> digits;

        while (num > 0)
        {
            digits.push_back(num % 10);
            num /= 10;
        }

        return digits;
    }

    long long build(const std::vector<int>& dgs)
    {
        auto n = 0LL;

        for (int i = std::size(dgs) - 1; i >= 0; i--)
        {
            n = 10 * n + dgs[i];
        }

        return n;
    }
};