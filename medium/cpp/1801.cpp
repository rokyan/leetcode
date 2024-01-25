// https://leetcode.com/problems/number-of-orders-in-the-backlog/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int getNumberOfBacklogOrders(std::vector<std::vector<int>>& orders)
    {
        std::priority_queue<std::pair<int, int>> buys;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> sells;

        for (const auto& order : orders)
        {
            const auto price = order[0];
            auto amount = order[1];
            const auto type = order[2];

            if (type == 0)
            {
                while (!sells.empty() && amount > 0 && sells.top().first <= price)
                {
                    auto sell = sells.top();
                    sells.pop();

                    const auto sub = std::min(sell.second, amount);
                    sell.second -= sub;
                    amount -= sub;

                    if (sell.second > 0)
                    {
                        sells.push(sell);
                    }
                }

                if (amount > 0)
                {
                    buys.push({ price, amount});
                }
            }
            else
            {
                while (!buys.empty() && amount > 0 && buys.top().first >= price)
                {
                    auto buy = buys.top();
                    buys.pop();

                    const auto sub = std::min(buy.second, amount);
                    buy.second -= sub;
                    amount -= sub;

                    if (buy.second > 0)
                    {
                        buys.push(buy);
                    }
                }

                if (amount > 0)
                {
                    sells.push({ price, amount });
                }
            }
        }

        auto res = 0;

        while (!buys.empty())
        {
            res += buys.top().second;
            res %= mod;
            buys.pop();
        }

        while (!sells.empty())
        {
            res += sells.top().second;
            res %= mod;
            sells.pop();
        }

        return res;
    }
};