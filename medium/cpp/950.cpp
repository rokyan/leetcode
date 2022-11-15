// https://leetcode.com/problems/reveal-cards-in-increasing-order/

class Solution
{
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck)
    {
        std::vector<std::size_t> order;
        order.reserve(std::size(deck));
        
        std::deque<std::size_t> indexes;
        
        for (std::size_t idx = 0; idx < std::size(deck); idx++)
        {
            indexes.push_back(idx);
        }
        
        while (!indexes.empty())
        {
            order.push_back(indexes.front());
            indexes.pop_front();
            indexes.push_back(indexes.front());
            indexes.pop_front();
        }
        
        std::sort(std::begin(deck), std::end(deck));
        
        std::vector<int> solution(std::size(deck));
        
        for (std::size_t pos = 0; pos < std::size(deck); pos++)
        {
            solution[order[pos]] = deck[pos];
        }
        
        return solution;
    }
};