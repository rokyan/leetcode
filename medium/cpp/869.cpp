// https://leetcode.com/problems/reordered-power-of-2/

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        int pow = 0;
        
        while ((1 << pow) <= 1e9)
        {
            if (check(n, 1 << pow))
            {
                return true;
            }
            
            pow++;
        }
        
        return false;
    }
    
private:
    bool check(int n, int target)
    {
        int cnt[10] = { 0 };
        
        while (target > 0)
        {
            cnt[target % 10]++;
            target /= 10;
        }
        
        while (n > 0)
        {
            cnt[n % 10]--;
            
            if (cnt[n % 10] < 0)
            {
                return false;
            }
            
            n /= 10;
        }
        
        for (int i = 0; i < 10; i++)
        {
            if (cnt[i] > 0)
            {
                return false;
            }
        }
        
        return true;
    }
};