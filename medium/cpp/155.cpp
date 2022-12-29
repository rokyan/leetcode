// https://leetcode.com/problems/min-stack/description/

class MinStack
{
public:
    MinStack() {}
    
    void push(int value)
    {
        if (!data.empty())
        {
            data.emplace_back(value, std::min(value, getMin()));
        }
        else
        {
            data.push_back({ value, value });
        }
    }
    
    void pop()
    {
        data.pop_back();
    }
    
    int top()
    {
        return data.back().first;
    }
    
    int getMin()
    {
        return data.back().second;
    }
    
private:
    std::vector<std::pair<int, int>> data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */