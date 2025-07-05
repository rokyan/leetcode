// https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/description/

class Solution
{
public:
    int minSwaps(std::vector<int>& nums)
    {
        auto odd = 0;
        auto even = 0;

        const auto n = std::size(nums);

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] % 2)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }

        if (n % 2 == 0 && (odd != n / 2 || even != n / 2))
        {
            return -1;
        }

        if (n % 2 == 1 && !(odd == n / 2 && even == n / 2 + 1 ||
            odd == n / 2 + 1 && even == n / 2))
        {
            return -1;
        }

        const auto [oddPos, evenPos] = splitPos(nums);

        if (n % 2 == 0)
        {
            return std::min(calc(oddPos, evenPos, 0, n), calc(oddPos, evenPos, 1, n));
        }

        return calc(oddPos, evenPos, (odd == n / 2 + 1) ? 1 : 0, n);
    }

private:
    std::tuple<std::vector<int>, std::vector<int>> splitPos(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> oddPos;
        oddPos.reserve(n);

        std::vector<int> evenPos;
        evenPos.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] % 2)
            {
                oddPos.push_back(i);
            }
            else
            {
                evenPos.push_back(i);
            }
        }

        return {oddPos, evenPos};
    }

    int calc(const std::vector<int>& oddPos, const std::vector<int>& evenPos, int val, int n)
    {
        auto oddPtr = 0;
        auto evenPtr = 0;
        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            if (val == 1)
            {
                const auto nextPos = oddPos[oddPtr++];
                res += std::abs(i - nextPos);
            }
            else
            {
                const auto nextPos = evenPos[evenPtr++];
                res += std::abs(i - nextPos);
            }

            val ^= 1;
        }

        return res / 2;
    }
};