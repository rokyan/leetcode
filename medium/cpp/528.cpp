// https://leetcode.com/problems/random-pick-with-weight/description/

class Solution
{
public:
    Solution(std::vector<int>& w)
        : weights { w }
        , gen { std::random_device{}() }
    {
        tot = std::accumulate(std::cbegin(weights), std::cend(weights), 0);

        std::partial_sum(std::begin(weights), std::end(weights), std::begin(weights));
    }
    
    int pickIndex()
    {
        auto r = get_rand();

        return std::distance(std::begin(weights), std::lower_bound(std::begin(weights), std::end(weights), r));
    }

private:
    int get_rand()
    {
        std::uniform_int_distribution<> distrib(1, tot);
        return distrib(gen);
    }

private:
    std::mt19937 gen;
    std::vector<int> weights;
    int tot;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */