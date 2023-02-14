// https://leetcode.com/problems/sort-the-jumbled-numbers/description/

class Solution
{
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums)
    {
        std::vector<std::pair<int, int>> data;
        data.reserve(std::size(nums));

        for (const auto& num : nums)
        {
            auto n = num;
            auto mapped = 0;

            for (auto m = 1, n = num; ; m *= 10)
            {
                mapped = m * mapping[n % 10] + mapped;
                n /= 10;
                
                if (n == 0)
                {
                    break;
                }
            }

            data.emplace_back(mapped, num);
        }

        std::stable_sort(std::begin(data), std::end(data), [](const auto& left, const auto& right) {
            return left.first < right.first;
        });

        std::vector<int> res;
        res.reserve(std::size(data));

        std::transform(std::begin(data), std::end(data), std::back_inserter(res), [](const auto& e) {
            return e.second;
        });

        return res;
    }
};