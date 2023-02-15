// https://leetcode.com/problems/design-a-food-rating-system/description/

class FoodRatings
{
private:
    struct comp
    {
    public:
        bool operator()(const std::pair<int, std::string>& left, const std::pair<int, std::string>& right) const noexcept
        {
            return left.first > right.first ||
                left.first == right.first && left.second < right.second;
        }
    };

public:
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings)
    {
        const auto n = std::size(foods);

        for (auto i = 0; i < n; i++)
        {
            by_food[foods[i]] = { ratings[i], cuisines[i] };
            by_cuisine[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }
    
    void changeRating(std::string food, int newRating)
    {
        auto& entry = by_food[food];
        by_cuisine[entry.second].erase({ entry.first, food });
        by_cuisine[entry.second].emplace(newRating, food);
        entry.first = newRating;
    }
    
    std::string highestRated(std::string cuisine)
    {
        auto& entry = by_cuisine[cuisine];
        return std::begin(entry)->second;
    }

private:
    std::unordered_map<std::string, std::pair<int, std::string>> by_food;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>, comp>> by_cuisine;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */