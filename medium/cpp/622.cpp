// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue
{
public:
    MyCircularQueue(int k)
        : max_size(k)
        , size(0)
        , head(0)
        , tail(0)
    {
        data.resize(k);
    }
    
    bool enQueue(int value)
    {
        if (size == max_size)
        {
            return false;
        }
        
        data[tail] = value;
        tail = (tail + 1) % max_size;
        size++;
        
        return true;
    }
    
    bool deQueue()
    {
        if (size == 0)
        {
            return false;
        }
        
        head = (head + 1) % max_size;
        size--;
        
        return true;
    }
    
    int Front()
    {
        return size == 0 ? -1 : data[head];
    }
    
    int Rear()
    {
        return size == 0 ? -1 : data[(tail + max_size - 1) % max_size];
    }
    
    bool isEmpty()
    {
        return size == 0;
    }
    
    bool isFull()
    {
        return size == max_size;
    }
    
private:
    std::vector<int> data;
    
    std::size_t max_size;
    std::size_t size;
    
    std::size_t head;
    std::size_t tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */