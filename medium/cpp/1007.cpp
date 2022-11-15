// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution
{
public:
    int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms)
    {       
        int result[4] = {};
        
        result[0] = solve_for_top(tops, bottoms);
        result[1] = solve_for_bottom(tops, bottoms);

        std::swap(tops.front(), bottoms.front());
        
        result[2] = solve_for_top(tops, bottoms, true);
        result[3] = solve_for_bottom(tops, bottoms, true);
        
        int answer = result[0];
        
        for (std::size_t idx = 1; idx < 4; idx++)
        {
            if (result[idx] != -1)
            {
                if (answer == -1)
                {
                    answer = result[idx];
                }
                else
                {
                    answer = std::min(answer, result[idx]);
                }
            }
        }
        
        return answer;
    }
    
private:
    int solve_for_top(const vector<int>& tops, const vector<int>& bottoms, bool first_swapped = false)
    {
        int op_count = 0;
        
        for (std::size_t pos = 1; pos < std::size(tops); pos++)
        {
            const int top = tops[pos];
            const int bottom = bottoms[pos];
            
            if (top == tops.front())
            {
                //
            }
            else if (bottom == tops.front())
            {
                op_count++;
            }
            else
            {
                return -1;
            }
        }
        
        return op_count + first_swapped;
    }
    
    int solve_for_bottom(const vector<int>& tops, const vector<int>& bottoms, bool first_swapped = false)
    {
        int op_count = 0;
        
        for (std::size_t pos = 1; pos < std::size(tops); pos++)
        {
            const int top = tops[pos];
            const int bottom = bottoms[pos];
            
            if (bottom == bottoms.front())
            {
                //
            }
            else if (top == bottoms.front())
            {
                op_count++;
            }
            else
            {
                return -1;
            }
        }
        
        return op_count + first_swapped;
    }
};