// https://leetcode.com/problems/count-pairs-in-two-arrays/description/

class Solution
{
private:
    class fwtree
    {
    public:
        fwtree(int n)
        {
            data.resize(n);
        }

        int sum(int r) const
        {
            auto res = 0;

            for (; r >= 0; r = (r & (r + 1)) - 1)
            {
                res += data[r];
            }

            return res;
        }

        void add(int pos, int value)
        {
            for (; pos < std::size(data); pos = (pos | (pos + 1)))
            {
                data[pos] += value;
            }
        }

    private:
        std::vector<int> data;
    };

public:
    long long countPairs(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto transform = [](auto value) {
            return 100001 + value;
        };

        fwtree tree{ 2 * 100001 };

        auto res = 0LL;

        for (auto i = 0; i < std::size(nums1); i++)
        {
            const auto diff = nums1[i] - nums2[i];
            res += tree.sum(transform(diff) - 1);
            tree.add(transform(-diff), 1);
        }

        return res;
    }
};