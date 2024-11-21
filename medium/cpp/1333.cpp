// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/

#include <ranges>

class Solution
{
public:
    std::vector<int> filterRestaurants(
        std::vector<std::vector<int>>& restaurants,
        int veganFriendly,
        int maxPrice,
        int maxDistance)
    {
        std::ranges::sort(restaurants, [](const auto& l, const auto& r) { return l[1] > r[1] || l[1] == r[1] && l[0] > r[0]; });
        auto ids = restaurants
            | std::views::filter([veganFriendly, maxPrice, maxDistance](const auto& e) {
                return (veganFriendly ? e[2] : true) &&
                    e[3] <= maxPrice &&
                    e[4] <= maxDistance; })
            | std::views::transform([](const auto& e) { return e[0]; });
        return std::vector(std::begin(ids), std::end(ids));
    }
};