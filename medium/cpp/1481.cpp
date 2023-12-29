// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

class Solution
{
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k)
    {
        std::unordered_map<int, int> freq;

        for (auto num : arr)
        {
            freq[num]++;
        }

        std::vector<int> tot;
        tot.reserve(std::size(freq));

        for (auto&& e : freq)
        {
            tot.push_back(e.second);
        }

        std::sort(std::begin(tot), std::end(tot));

        auto i = 0;

        for (; i < std::size(tot); i++)
        {
            k -= tot[i];

            if (k < 0)
            {
                break;
            }
        }

        return std::size(tot) - i;
    }
};