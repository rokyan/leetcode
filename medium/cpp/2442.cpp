// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/

class Solution
{
public:
    int countDistinctIntegers(vector<int>& nums)
    {
        std::unordered_set<int> un(std::begin(nums), std::end(nums));

        for (auto num : nums)
        {
            auto rev = 0;

            while (num > 0)
            {
                rev = 10 * rev + num % 10;
                num /= 10;
            }

            un.insert(rev);
        }

        return std::size(un);
    }
};