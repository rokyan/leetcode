// https://leetcode.com/problems/max-stack/description/

class MaxStack
{
public:
    MaxStack()
    {   
    }
    
    void push(int x)
    {
        elements.push_back(x);
        mapping[x].push_back(--std::end(elements));
    }
    
    int pop()
    {
        const auto e = elements.back();
        elements.pop_back();
        mapping[e].pop_back();

        if (mapping[e].empty())
        {
            mapping.erase(e);
        }

        return e;
    }
    
    int top()
    {
        return elements.back();
    }
    
    int peekMax()
    {
        return std::cbegin(mapping)->first;
    }
    
    int popMax()
    {
        const auto it = std::begin(mapping)->second.back();
        elements.erase(it);
        std::begin(mapping)->second.pop_back();

        const auto val = std::begin(mapping)->first;

        if (std::begin(mapping)->second.empty())
        {
            mapping.erase(std::begin(mapping));
        }

        return val;
    }

private:
    std::list<int> elements;
    std::map<int, std::vector<std::list<int>::iterator>, std::greater<int>> mapping;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */