// https://leetcode.com/problems/ugly-number-ii/description/

class Solution
{
private:
    using ll = long long;

public:
    int nthUglyNumber(int n)
    {
        std::priority_queue<ll, std::vector<ll>, std::greater<ll>> numbers;        
        std::unordered_set<ll> probe;
        
        numbers.push(1);
        probe.insert(1);
        
        while (n--)
        {
            const auto num = numbers.top();
            numbers.pop();
            
            if (!n)
            {
                return num;
            }
            
            for (auto m : { 2, 3, 5 })
            {
                const auto next = num * m;
                const auto not_exists = probe.insert(next).second;
                
                if (not_exists)
                {
                    numbers.push(next);
                }
            }
        }
        
        return 1;
    }
};