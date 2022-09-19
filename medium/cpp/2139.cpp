// https://leetcode.com/problems/minimum-moves-to-reach-target-score/

class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        if (target == 1)
        {
            return 0;
        }
        
        if (target & 1)
        {
            return 1 + minMoves(target ^ 1, maxDoubles);
        }
        
        if (maxDoubles > 0)
        {
            return 1 + minMoves(target >> 1, maxDoubles - 1);
        }
        
        return target - 1;
    }
};