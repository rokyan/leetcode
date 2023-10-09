// https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/

class Solution
{
public:
    int minimumBuckets(std::string hamsters)
    {
        const auto n = std::size(hamsters);

        for (auto i = 1; i + 1 < n; i++)
        {
            if (hamsters[i - 1] == 'H' && hamsters[i] == 'H' && hamsters[i + 1] == 'H')
            {
                return -1;
            }
        }

        std::vector<char> candy(n);

        for (auto i = 0; i < n; i++)
        {
            if (hamsters[i] == 'H')
            {
                if (i > 0 && candy[i - 1])
                {
                    continue;
                }
                
                if (i + 1 < n && hamsters[i + 1] == '.')
                {
                    candy[i + 1] = true;
                }
                else if (i > 0 && hamsters[i - 1] == '.')
                {
                    candy[i - 1] = true;
                }
                else
                {
                    return -1;
                }
            }
        }

        return std::count(std::begin(candy), std::end(candy), 1);
    }
};