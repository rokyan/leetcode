// https://leetcode.com/problems/maximum-transactions-without-negative-balance/description/

class Solution
{
public:
    int maxTransactions(std::vector<int>& transactions)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int res = 0;
        long long balance = 0;

        const int n = std::size(transactions);

        for (int i = 0; i < n; i++)
        {
            if (transactions[i] >= 0)
            {
                balance += transactions[i];
                res++;
            }
            else
            {
                if (balance + transactions[i] >= 0)
                {
                    pq.push(transactions[i]);
                    balance += transactions[i];
                    res++;
                }
                else
                {
                    if (!pq.empty() && pq.top() < transactions[i])
                    {
                        balance -= pq.top();
                        pq.pop();
                        balance += transactions[i];
                        pq.push(transactions[i]);
                    }
                }
            }
        }

        return res;
    }
};