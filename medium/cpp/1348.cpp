// https://leetcode.com/problems/tweet-counts-per-frequency/description/

class TweetCounts
{
public:
    TweetCounts() = default;
    
    void recordTweet(const std::string& tweetName, int time)
    {
        timesPerTweet[tweetName].insert(time);
    }
    
    std::vector<int> getTweetCountsPerFrequency(const std::string& freq,
        const std::string& tweetName, int startTime, int endTime)
    {
        if (const auto it = timesPerTweet.find(tweetName);
            it != timesPerTweet.end() && !it->second.empty())
        {
            auto jt = it->second.lower_bound(startTime);

            const int step = getStep(freq);
            const int times = (endTime - startTime + 1 + step - 1) / step;

            std::vector<int> res(times);

            for (int i = 0, last = startTime + step - 1; i < times && jt != it->second.end(); i++)
            {
                int cnt = 0;

                while (jt != it->second.end() && *jt <= std::min(last, endTime))
                {
                    cnt++;
                    ++jt;
                }

                res[i] = cnt;
                last += step;
            }

            return res;
        }

        return {};
    }

private:
    int getStep(const std::string& freq)
    {
        static std::unordered_map<std::string, int> freqToStep
        {
            {"minute", 60},
            {"hour", 60 * 60},
            {"day", 24 * 60 * 60}
        };

        return freqToStep[freq];
    }

private:
    std::unordered_map<std::string, std::multiset<int>> timesPerTweet;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */