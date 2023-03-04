// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

class Solution
{
private:
    class fenwick_tree
    {
    public:
        fenwick_tree(std::size_t n)
        {
            data.resize(n);
        }

        int get_sum(int right)
        {
            auto sum = 0;

            while (right >= 0)
            {
                sum += data[right];
                right = (right & (right + 1)) - 1;
            }

            return sum;
        }

        void update(int pos)
        {
            while (pos < std::size(data))
            {
                data[pos]++;
                pos = pos | (pos + 1);
            }
        }

    private:
        std::vector<int> data;
    };

public:
    long long numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int diff)
    {
        fenwick_tree tree{ 10001 * 6 };

        long long res = 0;

        const auto n = std::size(nums1);

        for (auto pos = 0; pos < n; pos++)
        {
            const auto cur = nums1[pos] - nums2[pos] + 3 * 10001;
            res += tree.get_sum(cur + diff);
            tree.update(cur);
        }

        return res;
    }
};