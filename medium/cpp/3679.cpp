// https://leetcode.com/problems/minimum-discards-to-balance-inventory/description/

class Solution
{
public:
    int minArrivalsToDiscard(const std::vector<int>& arrivals, int w, int m)
    {
        std::unordered_map<int, int> freq;
        std::vector<char> taken(arrivals.size());

        int res = 0;

        for (int i = 0; i < arrivals.size(); i++)
        {
            if (i >= w && taken[i - w])
            {
                freq[arrivals[i - w]]--;
            }

            if (freq[arrivals[i]] < m)
            {
                freq[arrivals[i]]++;
                taken[i] = true;
            }
            else
            {
                res++;
            }
        }

        return res;
    }
};