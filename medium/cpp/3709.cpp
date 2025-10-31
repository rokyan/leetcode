// https://leetcode.com/problems/design-exam-scores-tracker/description/

class ExamTracker
{
public:
    ExamTracker() = default;
    
    void record(int time, int score)
    {
        times.push_back(time);

        prefSums.push_back(prefSums.empty() ? 0 : prefSums.back());
        prefSums.back() += score;
    }
    
    long long totalScore(int startTime, int endTime)
    {
        const auto startIt = std::lower_bound(std::cbegin(times), std::cend(times), startTime);

        if (startIt == std::cend(times))
        {
            return 0;
        }

        if (*startIt > endTime)
        {
            return 0;
        }

        const auto endIt = std::upper_bound(std::cbegin(times), std::cend(times), endTime);

        const int startPos = std::distance(std::cbegin(times), startIt);
        const int endPos = std::distance(std::cbegin(times), endIt);

        long long sum = prefSums[endPos - 1];

        if (startPos > 0)
        {
            sum -= prefSums[startPos - 1];
        }

        return sum;
    }

private:
    std::vector<int> times;
    std::vector<long long> prefSums;
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */