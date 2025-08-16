// https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-ii/description/

class Solution
{
private:
    class Tree
    {
    public:
        Tree(std::size_t size)
            : data(size)
        {}

        void update(int pos, int value)
        {
            for (; pos < std::size(data); pos = (pos | (pos + 1)))
            {
                data[pos] += value;
            }
        }

        int sum(int l, int r)
        {
            return sum(r) - (l > 0 ? sum(l - 1) : 0);
        }

    private:
        int sum(int r)
        {
            auto res = 0;

            for (; r >= 0; r = (r & (r + 1)) - 1)
            {
                res += data[r];
            }

            return res;
        }
    
    private:
        std::vector<int> data;
    };

public:
    std::vector<int> popcountDepth(
        std::vector<long long>& nums,
        const std::vector<std::vector<long long>>& queries)
    {
        const auto n = std::size(nums);
        const auto queriesCount = std::size(queries);

        std::vector<int> res;
        res.reserve(queriesCount);

        std::vector<Tree> trees(6, Tree{n});

        for (auto idx = 0; idx < n; idx++)
        {
            trees[calcDepth(nums[idx])].update(idx, 1);
        }

        for (auto idx = 0; idx < queriesCount; idx++)
        {
            const auto& query = queries[idx];

            if (query[0] == 1)
            {
                const auto l = query[1];
                const auto r = query[2];
                const auto k = query[3];
                res.push_back(trees[k].sum(l, r));
            }
            else
            {
                const auto idx = query[1];
                const auto val = query[2];

                auto d = calcDepth(nums[idx]);

                if (d <= 5)
                {
                    trees[d].update(idx, -1);
                }

                nums[idx] = val;

                d = calcDepth(nums[idx]);

                if (d <= 5)
                {
                    trees[d].update(idx, 1);
                }
            }
        }

        return res;
    }

private:
    int count(long long x)
    {
        auto cnt = 0;

        while (x > 0)
        {
            cnt++;
            x &= (x - 1);
        }

        return cnt;
    }

    int calcDepth(long long x)
    {
        auto depth = 0;

        while (x > 1 && depth <= 5)
        {
            depth++;
            x = count(x);
        }

        return depth;
    }
};