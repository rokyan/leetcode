// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

class Solution
{
public:
    int longestCommonPrefix(const std::vector<int>& arr1, const std::vector<int>& arr2)
    {
        std::unordered_set<int> probe;

        for (auto num : arr1)
        {
            auto pref = num;

            while (pref && !probe.count(pref))
            {
                probe.insert(pref);
                pref /= 10;
            }
        }

        auto len = [](int x) {
            auto res = 0;
            while (x)
            {
                res++;
                x /= 10;
            }
            return res;
        };

        auto res = 0;

        for (auto num : arr2)
        {
            auto pref = num;
            auto t = len(pref);

            if (t <= res)
            {
                continue;
            }

            while (pref && t > res)
            {
                if (probe.find(pref) != std::end(probe))
                {
                    res = t;
                    break;
                }
                pref /= 10;
                t--;
            }
        }

        return res;
    }
};