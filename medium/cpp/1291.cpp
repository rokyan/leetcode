// https://leetcode.com/problems/sequential-digits/

class Solution
{
public:
    std::vector<int> sequentialDigits(int low, int high)
    {       
        std::vector<int> seq_numbers;
        
        for (int d = 1; d <= 9; d++)
        {
            auto num = d;
            
            while (num <= high)
            {
                if (num >= low)
                {
                    seq_numbers.push_back(num);
                }
                
                if (num % 10 < 9)
                {
                    num = num * 10 + num % 10 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        
        std::sort(std::begin(seq_numbers), std::end(seq_numbers));
        
        return seq_numbers;
    }
};