// https://leetcode.com/problems/beautiful-array/

class Solution
{
public:
    std::vector<int> beautifulArray(int n)
    {
        return solve(n);
    }
    
private:
    std::vector<int> solve(int n)
    {
        if (n == 1)
        {
            return { 1 };
        }
        
        auto left = solve(n / 2);
        auto right = solve(n - n / 2);
        
        std::for_each(std::begin(left), std::end(left), [](auto& e) { e *= 2; });
        std::for_each(std::begin(right), std::end(right), [](auto& e) { e = 2 * e - 1; });
        
        left.insert(std::end(left), std::begin(right), std::end(right));
        
        return left;
    }
};