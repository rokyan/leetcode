// https://leetcode.com/problems/friends-of-appropriate-ages/description/

class Solution
{
public:
    int numFriendRequests(std::vector<int>& ages)
    {
        const auto n = std::size(ages);

        std::sort(std::begin(ages), std::end(ages));

        auto res = 0;

        for (auto i = 0, l = 0, r = 0; i < n; i++)
        {
            while (r < n && ages[r] <= ages[i])
            {
                r++;
            }

            while (l < n && ages[l] <= 0.5 * ages[i] + 7)
            {
                l++;
            }

            // std::cout << l << " " << r << std::endl;

            if (r > l)
            {
                res += r - l - 1;
            }
        }

        return res;
    }
};