// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
    {
        const auto n = std::size(people);
        
        std::sort(std::begin(people), std::end(people),
                  [](const auto& p1, const auto& p2) { return p1[0] < p2[0] || p1[0] == p2[0] && p1[1] > p2[1]; });
        
        std::vector<char> used(n);
        std::vector<std::vector<int>> answer(n);
        
        for (const auto& person : people)
        {
            auto pos = 0;
            auto times = person[1];
            
            while (true)
            {
                if (used[pos])
                {
                    pos++;
                    continue;
                }
                
                if (times == 0)
                {
                    break;
                }
                else
                {
                    times--;
                    pos++;
                }
            }
            
            used[pos] = true;
            answer[pos] = person;
        }
        
        return answer;
    }
};