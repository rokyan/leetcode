class Solution
{
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k)
    {
        std::deque<int> q;

        auto add = [&q](int num)
        {
            while (!q.empty() && q.back() < num)
            {
                q.pop_back();
            }

            q.push_back(num);
        };

        for (auto i = 0; i + 1 < k; i++)
        {
            add(nums[i]);
        }

        std::vector<int> res;
        res.reserve(std::size(nums));

        for (auto i = k - 1; i < std::size(nums); i++)
        {
            add(nums[i]);

            res.push_back(q.front());
            
            if (q.front() == nums[i - k + 1])
            {
                q.pop_front();
            }
        }

        return res;
    }
};