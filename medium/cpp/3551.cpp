// https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/

class Solution
{
public:
    int minSwaps(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<std::pair<int, int>> valsWithPos(n);

        for (auto i = 0; i < n; i++)
        {
            valsWithPos[i] = {nums[i], i};
        }

        auto comp = [this](const auto& left, const auto& right) {
            const auto leftSum = sum(left.first);
            const auto rightSum = sum(right.first);

            return leftSum < rightSum
                || leftSum == rightSum && left.first < right.first;
        };

        std::ranges::sort(valsWithPos, comp);

        auto res = 0;

        std::vector<char> visited(n);

        for (auto i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }

            auto next = i;
            auto cnt = 0;

            while (!visited[next])
            {
                visited[next] = true;
                next = valsWithPos[next].second;
                cnt++;
            }

            res += cnt - 1;
        }

        return res;
    }

private:
    int sum(int x)
    {
        auto res = 0;

        while (x)
        {
            res += x % 10;
            x /= 10;
        }

        return res;
    }
};