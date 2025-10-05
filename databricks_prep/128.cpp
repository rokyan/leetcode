class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> numsSet(std::cbegin(nums), std::cend(nums));
        int res = 0;

        for (int i = 0; i < std::size(nums); i++)
        {
            auto cur = nums[i];

            if (numsSet.count(cur - 1))
            {
                continue;
            }

            int len = 0;

            for (;;)
            {
                const auto it = numsSet.find(cur);

                if (it == std::cend(numsSet))
                {
                    break;
                }

                numsSet.erase(it);

                len++;
                cur++;
            }

            res = std::max(res, len);
        }

        return res;
    }
};