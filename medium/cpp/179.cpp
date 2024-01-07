// https://leetcode.com/problems/largest-number/description/

class Solution
{
public:
    std::string largestNumber(std::vector<int>& nums)
    {
        std::vector<std::string> snums;
        snums.reserve(std::size(nums));

        std::transform(std::cbegin(nums), std::cend(nums), std::back_inserter(snums), [](auto num) {
            return std::to_string(num);
        });

        auto sorter = [](const std::string& num1, const std::string& num2) {
            return num1 + num2 > num2 + num1;
        };

        std::sort(std::begin(snums), std::end(snums), sorter);

        auto res = std::string{};

        for (const auto& snum : snums)
        {
            res += snum;
        }

        if (res[0] == '0')
        {
            return "0";
        }

        return res;
    }
};