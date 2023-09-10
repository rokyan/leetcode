// https://leetcode.com/problems/minimum-time-difference/description/

class Solution
{
private:
    static constexpr auto DELIM_POS = 2;

public:   
    int findMinDifference(std::vector<std::string>& timePoints)
    {
        const auto n = std::size(timePoints);

        std::vector<int> times(n);
        
        for (auto i = 0; i < n; i++)
        {
            const auto hours = std::stoi(timePoints[i].substr(0, DELIM_POS));
            const auto mins = std::stoi(timePoints[i].substr(DELIM_POS + 1));

            times[i] = hours * 60 + mins;
        }
        
        std::sort(std::begin(times), std::end(times));
        
        auto answer = 24 * 60 + times.front() - times.back();
        
        for (auto i = 1; i < std::size(times); ++i)
        {
            answer = std::min(answer, times[i] - times[i - 1]);
        }
        
        return answer;
    }
};