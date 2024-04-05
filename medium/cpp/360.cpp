// https://leetcode.com/problems/sort-transformed-array/description/

class Solution
{
public:
    vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c)
    {
        std::transform(std::cbegin(nums), std::cend(nums), std::begin(nums), [a, b, c](auto x) {
            return a * x * x + b * x + c;
        });

        auto max_e = *std::max_element(std::cbegin(nums), std::cend(nums), [](auto x, auto y) {
            return std::abs(x) < std::abs(y);
        });

        auto max_d = 0;

        while (max_e)
        {
            max_d++;
            max_e /= 10;
        }

        for (auto i = 0, d = 1; i < max_d; i++, d *= 10)
        {
            sort_iteration(nums, d);
        }

        std::vector<int> pos, neg;
        pos.reserve(std::size(nums));
        neg.reserve(std::size(nums));

        for (auto num : nums)
        {
            if (num >= 0)
            {
                pos.push_back(num);
            }
            else
            {
                neg.push_back(num);
            }
        }

        std::reverse(std::begin(neg), std::end(neg));

        std::merge(std::cbegin(neg), std::cend(neg), std::cbegin(pos), std::cend(pos), std::begin(nums));

        return nums;
    }

private:
    void sort_iteration(std::vector<int>& nums, int d)
    {
        std::vector<std::vector<int>> groups(10);

        for (auto num : nums)
        {
            const auto digit = std::abs(num) / d % 10;
            groups[digit].push_back(num);
        }

        auto pos = 0;

        for (const auto& group : groups)
        {
            for (auto num : group)
            {
                nums[pos++] = num;
            }
        }
    }
};