// https://leetcode.com/problems/design-circular-deque/description

class MyCircularDeque
{
public:
    MyCircularDeque(int k)
        : k{k}
        , data(k)
    {
    }
    
    bool insertFront(int value)
    {
        if (count == k)
        {
            return false;
        }

        head = (head - 1 + k) % k;
        data[head] = value;
        count++;

        return true;
    }
    
    bool insertLast(int value)
    {
        if (count == k)
        {
            return false;
        }

        data[tail] = value;
        tail = (tail + 1) % k;
        count++;

        return true;        
    }
    
    bool deleteFront()
    {
        if (count == 0)
        {
            return false;
        }

        head = (head + 1) % k;
        count--;

        return true;
    }
    
    bool deleteLast()
    {
        if (count == 0)
        {
            return false;
        }

        tail = (tail - 1 + k) % k;
        count--;

        return true;
    }
    
    int getFront() const noexcept
    {
        if (isEmpty())
        {
            return -1;
        }

        return data[head];
    }
    
    int getRear() const noexcept
    {
        if (isEmpty())
        {
            return -1;
        }

        return data[(tail - 1 + k) % k];
    }
    
    bool isEmpty() const noexcept
    {
        return count == 0;
    }
    
    bool isFull() const noexcept
    {
        return count == k;
    }

private:
    std::vector<int> data;
    int k;
    int count = 0;
    int head = 0;
    int tail = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */