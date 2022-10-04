// https://leetcode.com/problems/maximum-swap/

class Solution
{
public:
    int maximumSwap(int num)
    {
        std::vector<int> digits;
        
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        std::reverse(std::begin(digits), std::end(digits));
        
        for (int i = 0; i + 1 < std::size(digits); i++)
        {
            int idx = i;
            
            for (int j = i + 1; j < std::size(digits); j++)
            {
                if (digits[j] >= digits[idx])
                {
                    idx = j;
                }
            }
            
            if (idx != i && digits[idx] > digits[i])
            {
                std::swap(digits[i], digits[idx]);
                break;
            }
        }
               
        for (auto d : digits)
        {
            num = 10 * num + d;
        }
        
        return num;
    }
};