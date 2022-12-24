// https://leetcode.com/problems/sort-integers-by-the-power-value/description/

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        std::unordered_map<int, int> mem;
        mem[1] = 0;

        std::vector<std::pair<int, int>> numsWithPows;
        numsWithPows.reserve(hi - lo + 1);
        
        for (int num = lo; num <= hi; num++)
        {
            const auto pow = rec(num, mem);
            
            numsWithPows.emplace_back(pow, num);
        }
        
        auto it = std::begin(numsWithPows);
        std::advance(it, k - 1);
        
        std::nth_element(std::begin(numsWithPows), it, std::end(numsWithPows));
        
        return it->second;
    }
    
private:
    int rec(int num, std::unordered_map<int, int>& mem)
    {
        const auto it = mem.find(num);
        
        if (it != std::end(mem))
        {
            return it->second;
        } else
        {
            const auto pow = rec(num & 1 ? num * 3 + 1 : num >> 1, mem);
            mem[num] = pow + 1;
            return pow + 1;
        }
    }
};