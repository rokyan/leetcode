// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager
{
public:
    SeatManager(int n)
    {
    }
    
    int reserve()
    {
        if (!heap.empty())
        {
            const auto seat = heap.top();
            heap.pop();
            return -seat;
        }

        return last++;
    }
    
    void unreserve(int seatNumber)
    {
        heap.push(-seatNumber);
    }

private:
    int last = 1;
    std::priority_queue<int> heap;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */