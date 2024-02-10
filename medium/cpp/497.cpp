// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

class Solution
{
public:
    Solution(std::vector<std::vector<int>>& rects)
        : gen{ random_device() }
        , total{ 0 }
    {
        for (const auto& rect : rects)
        {
            const auto area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            sq.push_back(area + (sq.empty() ? 0 : sq.back()));
            total += area;
        }

        this->rects = std::move(rects);
    }
    
    std::vector<int> pick()
    {
        std::uniform_int_distribution<int> d{ 1, total };
        auto val = d(gen);
    
        auto idx = std::distance(std::cbegin(sq), std::lower_bound(std::cbegin(sq), std::cend(sq), val));

        std::uniform_int_distribution<int> d2{ 0, (rects[idx][2] - rects[idx][0] + 1) * (rects[idx][3] - rects[idx][1] + 1) - 1 };
        val = d2(gen);

        auto a = rects[idx][0] + (val % (rects[idx][2] - rects[idx][0] + 1));
        auto b = rects[idx][1] + (val / (rects[idx][2] - rects[idx][0] + 1));

        return { a, b };
    }

private:
    std::random_device random_device;
    std::mt19937 gen;

    std::vector<int> sq;
    int total;

    std::vector<std::vector<int>> rects;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */