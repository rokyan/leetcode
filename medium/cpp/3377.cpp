// https://leetcode.com/problems/digit-operations-to-make-two-integers-equal/description/

class Solution
{
public:
    int minOperations(int n, int m)
    {
        if (isPrime(n))
        {
            return -1;
        }

        std::unordered_map<int, int> distance{{ n, n }};
        std::set<std::pair<int, int>> q{{ n, n }};

        while (!q.empty())
        {
            auto [d, x] = *std::begin(q);
            q.erase(std::begin(q));

            auto c = x;
            auto t = 0;

            while (c > 0)
            {
                t++;
                c /= 10;
            }

            for (auto i = 0, p = 10; i < t; i++, p *= 10)
            {
                const auto digit = x % p / (p / 10);

                if (digit > 0)
                {
                    const auto next = x - p / 10;

                    if (!isPrime(next))
                    {
                        const auto cost = d + next;

                        if (const auto it = distance.find(next); it == std::end(distance) ||
                            it->second > cost)
                        {
                            if (it != std::end(distance))
                            {
                                q.erase({ it->second, next });
                                it->second = cost;
                            }
                            else
                            {
                                distance.emplace(next, cost);
                            }

                            q.insert({ cost, next });
                        }
                    }
                }

                if (digit < 9)
                {
                    const auto next = x + p / 10;

                    if (!isPrime(next))
                    {
                        const auto cost = d + next;

                        if (const auto it = distance.find(next); it == std::end(distance) ||
                            it->second > cost)
                        {
                            if (it != std::end(distance))
                            {
                                q.erase({ it->second, next });
                                it->second = cost;
                            }
                            else
                            {
                                distance.emplace(next, cost);
                            }

                            q.insert({ cost, next });
                        }
                    }
                }
            }
        }

        if (const auto it = distance.find(m); it != std::end(distance))
        {
            return it->second;
        }

        return -1;
    }

private:
    bool isPrime(int x)
    {
        if (x == 1)
        {
            return false;
        }

        for (auto i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};