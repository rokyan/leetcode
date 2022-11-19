// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution
{
public:
    std::vector<int> minOperations(std::string boxes)
    {
        const auto boxes_count = std::size(boxes);
               
        std::vector<int> left_counts(boxes_count);
        std::vector<int> right_counts(boxes_count);
        
        for (int pos = 0, count = 0; pos < std::size(boxes); pos++)
        {
            if (pos > 0)
            {
               left_counts[pos] = left_counts[pos - 1];
            }
            
            left_counts[pos] += count;
            
            if (boxes[pos] == '1')
            {
                count++;
            }
        }
        
        for (int pos = std::size(boxes) - 1, count = 0; pos >= 0; pos--)
        {
            if (pos + 1 < std::size(boxes))
            {
               right_counts[pos] = right_counts[pos + 1];
            }
            
            right_counts[pos] += count;
            
            if (boxes[pos] == '1')
            {
                count++;
            }
        }
        
        std::vector<int> answer(boxes_count);
        
        for (std::size_t pos = 0; pos < std::size(boxes); pos++)
        {
            answer[pos] = left_counts[pos] + right_counts[pos];
        }
        
        return answer;
    }
};