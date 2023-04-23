// https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/

class SummaryRanges
{
public:
    SummaryRanges()
    {
        
    }
    
    void addNum(int value)
    {
        nums.insert(value);
    }
    
    std::vector<std::vector<int>> getIntervals()
    {
        std::vector<std::vector<int>> res;

        for (auto num : nums)
        {
            if (res.empty() || res.back()[1] + 1 != num)
            {
                res.push_back({ num, num });
            }
            else
            {
                res.back()[1]++;
            }
        }

        return res;
    }

private:
    std::set<int> nums;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */