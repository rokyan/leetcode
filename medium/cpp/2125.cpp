// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution
{
public:
    int numberOfBeams(std::vector<string>& bank)
    {     
        auto last = 0;
        auto answer = 0;
        
        for (std::size_t i = 0; i < std::size(bank); i++)
        {
            int count = std::count_if(std::begin(bank[i]), std::end(bank[i]), [](auto e) { return e == '1'; });
            
            if (count > 0)
            {
                answer += last * count;
                last = count;
            }
        }
        
        return answer;
    }
};