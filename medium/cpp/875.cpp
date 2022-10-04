// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
public:
    int minEatingSpeed(std::vector<int>& piles, int h)
    {
        int lo = 1;
        int hi = *std::max_element(std::begin(piles), std::end(piles));
        
        while (lo < hi)
        {
            const int mid = lo + (hi - lo) / 2;
            
            if (solve(piles, h, mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
private:
    bool solve(const std::vector<int>& piles, int h, int k)
    {
        for (auto pile : piles)
        {
            h -= (pile + k - 1) / k;
            
            if (h < 0)
            {
                return false;
            }
        }
        
        return true;
    }
};