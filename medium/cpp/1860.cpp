// https://leetcode.com/problems/incremental-memory-leak/

class Solution
{
public:
    std::vector<int> memLeak(int memory1, int memory2)
    {
        for (int time = 1; ; time++)
        {
            if (time > std::max(memory1, memory2))
            {
                return { time, memory1, memory2 };
            }
            
            if (memory1 >= memory2)
            {
                memory1 -= time;
            }
            else
            {
                memory2 -= time;
            }
        }
    }
};