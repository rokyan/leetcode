// https://leetcode.com/problems/count-almost-equal-pairs-i/description/

class Solution
{
public:
    int countPairs(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto res = 0;

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                if (almost_equal(nums[i], nums[j]))
                {
                    res++;
                }
            }
        }

        return res;
    }

private:
    bool almost_equal(auto x, auto y)
    {
        auto sx = std::to_string(x);
        auto sy = std::to_string(y);

        for (auto i = 0; i < std::size(sx); i++)
        {
            for (auto j = i; j < std::size(sx); j++)
            {
                std::swap(sx[i], sx[j]);

                if (std::stoi(sx) == y)
                {
                    return true;
                }

                std::swap(sx[i], sx[j]);
            }
        }

        for (auto i = 0; i < std::size(sy); i++)
        {
            for (auto j = i; j < std::size(sy); j++)
            {
                std::swap(sy[i], sy[j]);

                if (std::stoi(sy) == x)
                {
                    return true;
                }

                std::swap(sy[i], sy[j]);
            }
        }

        return false;
    }
};