// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

class Solution
{
public:
    int getMinSwaps(std::string num, int k)
    {
        const std::string original_num { num };
        
        while (k--)
        {
            std::next_permutation(std::begin(num), std::end(num));
        }
        
        return count_swaps(num, original_num);
    }
    
private:   
    int count_swaps(std::string& num, const std::string& original_num)
    {
        int result = 0;
        
        for (std::size_t pos = 0; pos < std::size(num); pos++)
        {
            if (num[pos] != original_num[pos])
            {
                std::size_t next = pos + 1;
                
                for (; next < std::size(num); next++)
                {
                    if (num[next] == original_num[pos])
                    {
                        break;
                    }
                }
                
                while (next != pos)
                {
                    std::swap(num[next - 1], num[next]);
                    next--;
                    result++;
                }
            }
        }
        
        return result;
    }
};