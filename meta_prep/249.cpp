#include <ranges>

class Solution
{
private:
    using hash_type = unsigned long long;

    static constexpr hash_type hash_base = 31;

public:
    std::vector<std::vector<std::string>> groupStrings(const std::vector<std::string>& strings)
    {
        std::unordered_map<hash_type, std::vector<std::string>> mapper;

        for (const auto& s : strings)
        {
            const auto hash_value = calc_hash(s);
            mapper[hash_value].push_back(s);
        }

        const auto values_view = std::views::values(mapper);

        return std::vector<std::vector<std::string>>(
            std::cbegin(values_view), std::cend(values_view));
    }

private:
    hash_type calc_hash(std::string s)
    {
        const auto shift = s[0] - 'a';

        hash_type hash_value = 0;
        hash_type p = 1;

        for (auto c : s)
        {
            const auto code = (c - 'a' - shift + 26) % 26 + 1;
            hash_value += code * p;
            p *= hash_base;
        }

        return hash_value;
    }
};