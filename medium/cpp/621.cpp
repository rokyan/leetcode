// https://leetcode.com/problems/task-scheduler/description/

class Solution
{
public:
    int leastInterval(std::vector<char>& tasks, int n)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : tasks)
        {
            freq[c - 'A']++;
        }

        std::array<int, 26> last{ 0 };

        auto ts = 0;
      
        for (auto tot = static_cast<int>(std::size(tasks)); tot; ts++)
        {
            auto c = -1;

            for (auto i = 0; i < 26; i++)
            {
                if (freq[i] > 0 && last[i] <= ts && (c == -1 || freq[i] > freq[c]))
                {
                    c = i;
                }
            }

            if (c != -1)
            {
                tot--;
                freq[c]--;
                last[c] += n + 1;
            }
        }
 
        return ts;
    }
};