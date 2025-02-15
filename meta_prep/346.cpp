class MovingAverage
{
public:
    MovingAverage(int size)
        : head{0}
        , count{0}
        , sum{0}
    {    
        buffer.resize(size);   
    }
    
    double next(int val)
    {
        sum += val;

        if (count == std::size(buffer))
        {
            const auto tail = (head + 1) % std::size(buffer);
            sum -= buffer[tail];
        }
        else
        {
            count++;
        }

        head = (head + 1) % std::size(buffer);
        buffer[head] = val;

        return (sum + .0) / count;
    }

private:
    int head;
    int count;
    int sum;
    std::vector<int> buffer;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */