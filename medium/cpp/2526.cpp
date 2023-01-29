// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/

class DataStream
{
public:
    DataStream(int value, int k)
        : value{ value }
        , k{ k }
        , cnt{ 0 }
    {}
    
    bool consec(int num)
    {
        if (num == value)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        return (cnt >= k);
    }

private:
    int value;
    int k;
    int cnt;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */