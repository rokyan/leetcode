#include <ranges>

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        auto len = std::size(strs.front());

        for (const auto& str : strs | std::views::drop(1))
        {
            auto upd = 0;

            while (upd < std::min(len, std::size(str)) && strs.front()[upd] == str[upd])
            {
                upd++;
            }

            len = std::min<std::size_t>(len, upd);
        }

        return strs.front().substr(0, len);
    }
};