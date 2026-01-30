// https://leetcode.com/problems/design-front-middle-back-queue/description/

class FrontMiddleBackQueue
{
public:
    FrontMiddleBackQueue() = default;
    
    void pushFront(int val)
    {
        size++;
        front.push_front(val);
        rebalance();
    }
    
    void pushMiddle(int val)
    {
        size++;
        back.push_front(val);
        rebalance();
    }
    
    void pushBack(int val)
    {
        size++;
        back.push_back(val);
        rebalance();
    }
    
    int popFront()
    {
        if (empty())
        {
            return -1;
        }

        size--;

        int val = -1;

        if (!front.empty())
        {
            val = front.front();
            front.pop_front();
        }
        else
        {
            val = back.front();
            back.pop_front();
        }

        rebalance();
        return val;
    }
    
    int popMiddle()
    {
        if (empty())
        {
            return -1;
        }

        size--;
        
        if (front.size() == back.size())
        {
            const int val = front.back();
            front.pop_back();
            rebalance();
            return val;
        }
        else
        {
            const int val = back.front();
            back.pop_front();
            rebalance();
            return val;
        }     
    }
    
    int popBack()
    {
        if (empty())
        {
            return -1;
        }

        size--;
        const int val = back.back();
        back.pop_back();
        rebalance();
        return val;       
    }

private:
    void rebalance()
    {
        if (back.size() > front.size() + 1)
        {
            front.push_back(back.front());
            back.pop_front();
        }
        else if (front.size() > back.size())
        {
            back.push_front(front.back());
            front.pop_back();
        }
    }

private:
    bool empty() const noexcept
    {
        return size == 0;
    }

private:
    int size{0};
    std::deque<int> front;
    std::deque<int> back;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */