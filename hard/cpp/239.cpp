// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::multiset<int> run;

        for (auto i = 0; i + 1 < k; i++)
        {
            run.insert(nums[i]);
        }

        std::vector<int> res;
        res.reserve(std::size(nums));

        for (auto i = k - 1; i < std::size(nums); i++)
        {
            run.insert(nums[i]);
            res.push_back(*std::rbegin(run));
            run.erase(run.find(nums[i - k + 1]));
        }

        return res;
    }
};