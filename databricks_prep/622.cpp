class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    : size{k}
    , head{0}
    , tail{0}
    , count{0}
    {
        data.resize(size);
    }
    
    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        data[tail] = value;
        tail = (tail + 1) % size;
        count++;
        return true;
    }
    
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        head = (head + 1) % size;
        count--;
        return true;
    }
    
    int Front() const noexcept
    {
        if (isEmpty())
        {
            return -1;
        }

        return data[head];
    }
    
    int Rear() const noexcept
    {
        if (isEmpty())
        {
            return -1;
        }

        return data[(tail - 1 + size) % size];
    }
    
    bool isEmpty() const noexcept
    {
        return count == 0;
    }
    
    bool isFull() const noexcept
    {
        return count == size;
    }

private:
    std::vector<int> data;
    int size;
    int head;
    int tail;
    int count;
};