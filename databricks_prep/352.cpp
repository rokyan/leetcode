class SummaryRanges
{
public:
    SummaryRanges() = default;
    
    void addNum(int value)
    {
        auto rightIt = intervals.upper_bound(value);
 
        if (rightIt != std::cbegin(intervals))
        {
            auto leftIt = rightIt;
            --leftIt;

            if (leftIt->second + 1 < value)
            {
                leftIt = intervals.emplace(value, value).first;
            }
            else if (leftIt->second + 1 == value)
            {
                leftIt->second++;
            }

            if (rightIt != std::cend(intervals))
            {
                if (leftIt->second + 1 == rightIt->first)
                {
                    leftIt->second = rightIt->second;
                    intervals.erase(rightIt);
                }
            }
        }
        else
        {
            auto leftIt = intervals.emplace(value, value).first;

            if (rightIt != std::cend(intervals))
            {
                if (leftIt->second + 1 == rightIt->first)
                {
                    leftIt->second = rightIt->second;
                    intervals.erase(rightIt);
                }
            }
        }
    }
    
    std::vector<std::vector<int>> getIntervals()
    {
        std::vector<std::vector<int>> res;
        res.reserve(std::size(intervals));

        for (const auto& [key, value] : intervals)
        {
            res.push_back({key, value});
        }

        return res;
    }

private:
    std::map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */