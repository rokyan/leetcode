// https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/

class Solution
{
public:
    int minJumps(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, std::vector<int>> idxs;

        for (auto i = 0; i < n; i++)
        {
            if (isPrime(nums[i]))
            {
                idxs[nums[i]].push_back(i);
            }
        }

        std::vector<int> d(n, 2 * n);
        d[n - 1] = 0;

        std::queue<int> q;
        q.push(n - 1);

        while (!q.empty())
        {
            const auto idx = q.front();
            q.pop();

            if (idx > 0 && d[idx - 1] == 2 * n)
            {
                d[idx - 1] = d[idx] + 1;
                q.push(idx - 1);
            }

            if (idx + 1 < n && d[idx + 1] == 2 * n)
            {
                d[idx + 1] = d[idx] + 1;
                q.push(idx + 1);
            }

            auto val = nums[idx];

            auto div = 2;

            while (div * div <= val)
            {
                if (val % div == 0)
                {
                    if (const auto it = idxs.find(div); it != std::cend(idxs))
                    {
                        for (auto to : it->second)
                        {
                            if (d[to] == 2 * n)
                            {
                                d[to] = d[idx] + 1;
                                q.push(to);
                            }
                        }
                    }

                    idxs.erase(div);
                }

                while (val % div == 0)
                {
                    val /= div;
                }

                div++;
            }

            if (val > 1)
            {
                if (const auto it = idxs.find(val); it != std::cend(idxs))
                {
                    for (auto to : it->second)
                    {
                        if (d[to] == 2 * n)
                        {
                            d[to] = d[idx] + 1;
                            q.push(to);
                        }
                    }
                }

                idxs.erase(val);
            }
        }

        return d.front();
    }

private:
    bool isPrime(int x)
    {
        if (x <= 1)
        {
            return false;
        }

        for (auto d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                return false;
            }
        }

        return true;
    }
};