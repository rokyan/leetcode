// https://leetcode.com/problems/rle-iterator/description/

class RLEIterator
{
public:
    RLEIterator(std::vector<int>& encoding)
        : encoding{ encoding }
        , idx{ 0 }
    {        
    }
    
    int next(int n)
    {
        if (idx == std::size(encoding))
        {
            return -1;
        }

        if (n <= encoding[idx])
        {
            encoding[idx] -= n;
            return encoding[idx + 1];
        }
        else
        {
            n -= encoding[idx];
            idx += 2;
            return next(n);
        }
    }

private:
    std::vector<int> encoding;
    std::size_t idx;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */