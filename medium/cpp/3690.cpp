// https://leetcode.com/problems/split-and-merge-array-transformation/description/

template <typename T>
struct VectorHash
{
    std::size_t operator()(const std::vector<T>& v) const noexcept
    {
        std::size_t hash = v.size();
        std::hash<T> hasher;

        for (const T& x : v)
        {
            hash ^= hasher(x) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }

        return hash;
    }
};

class Solution
{
public:
    int minSplitMerge(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        const int n = nums1.size();

        std::unordered_map<std::vector<int>, int, VectorHash<int>> dist;
        dist[nums1] = 0;

        std::queue<std::vector<int>> q;
        q.push(nums1);

        std::vector<int> rem;
        std::vector<int> state;

        while (!q.empty())
        {
            const auto nums = std::move(q.front());
            q.pop();

            // Iterate over new split-and-merge lists
            for (int l = 0; l < n; l++)
            {
                for (int r = l; r < n; r++)
                {
                    const int tot = r - l + 1;

                    if (tot == n)
                    {
                        continue;
                    }

                    rem.clear();

                    for (int k = 0; k < l; k++)
                    {
                        rem.push_back(nums[k]);
                    }

                    for (int k = r + 1; k < n; k++)
                    {
                        rem.push_back(nums[k]);
                    }

                    const int len = rem.size();

                    for (int take = 0; take <= len; take++)
                    {
                        state.clear();

                        for (int i = 0; i < take; i++)
                        {
                            state.push_back(rem[i]);
                        }

                        for (int i = l; i <= r; i++)
                        {
                            state.push_back(nums[i]);
                        }

                        for (int i = take; i < len; i++)
                        {
                            state.push_back(rem[i]);
                        }

                        const int stateDist = dist[nums] + 1;

                        if (dist.emplace(state, stateDist).second)
                        {
                            q.push(std::move(state));
                        }
                    }
                }
            }
        }

        return dist[nums2];
    }
};