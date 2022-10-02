// https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution
{
public:
    int minStoneSum(std::vector<int>& piles, int k)
    {
        std::priority_queue<int> pq(std::begin(piles), std::end(piles));
        
        while (k--)
        {
            const auto num = pq.top();
            pq.pop();
            pq.push(num - num / 2);
        }
        
        auto sum = 0;
        
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};