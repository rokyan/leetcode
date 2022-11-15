// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack
{
public:
    CustomStack(int maxSize)
        : maxSize(maxSize)
        , size(0)
    {
        data.resize(maxSize);
        inc.resize(maxSize);
    }
    
    void push(int x)
    {
        if (size < maxSize)
        {
            data[size++] = x;
        }
    }
    
    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            size--;
            
            const auto popped_value = data[size] + inc[size];
            
            if (size > 0)
            {
                inc[size - 1] += inc[size];
            }
            
            inc[size] = 0;
            
            return popped_value;
        }
    }
    
    void increment(int k, int val)
    {
        if (size > 0)
        {
            k = std::min(k, size);
            inc[k - 1] += val;   
        }
    }
    
private:
    std::vector<int> data;
    std::vector<int> inc;
    
    int maxSize;
    int size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */