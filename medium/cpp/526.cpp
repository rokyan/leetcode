// https://leetcode.com/problems/beautiful-arrangement/description/

class Solution
{
public:
    int countArrangement(int n)
    {
       std::vector<int> elems(n);
       
       for (auto i = 0; i < n; ++i)
       {
           elems[i] = i + 1;
       }
       
       return count(0, elems);
    }

private:
    int count(std::size_t pos, std::vector<int>& elems)
    {
        if (pos == std::size(elems))
        {
            return 1;
        }
        
        auto sum = 0;
        
        for (std::size_t idx = pos; idx < std::size(elems); ++idx)
        {
            const auto value = elems[idx];
            
            if ((pos + 1) % value == 0 || value % (pos + 1) == 0)
            {
                std::swap(elems[idx], elems[pos]);
                sum += count(pos + 1, elems);
                std::swap(elems[idx], elems[pos]);
            }
        }
        
        return sum;
    }
};