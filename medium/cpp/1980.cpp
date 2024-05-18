// https://leetcode.com/problems/find-unique-binary-string/description/

class Solution
{
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums)
    {
        std::unordered_set<int> probe;

        std::transform(std::cbegin(nums), std::cend(nums), std::inserter(probe, std::begin(probe)), [](const auto& e) {
            return std::stoi(e, nullptr, 2);
        });

        const auto n = std::size(nums.front());

        for (auto mask = 0; mask < (1 << n); mask++)
        {
            if (probe.find(mask) == std::cend(probe))
            {
                std::string res;
                auto r = mask;

                while (r)
                {
                    res.push_back('0' + r % 2);
                    r /= 2;
                }

                while (std::size(res) < n)
                {
                    res.push_back('0');
                }

                std::reverse(std::begin(res), std::end(res));

                return res;
            }
        }

        return "";
    }
};