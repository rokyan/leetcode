// https://leetcode.com/problems/design-an-atm-machine/description/

class ATM
{
public:
    ATM()
        : vals{ 20, 50, 100, 200, 500 }
    {
        banknotesCount.resize(5);
    }
    
    void deposit(std::vector<int> banknotesCount)
    {
        for (auto i = 0; i < 5; i++)
        {
            this->banknotesCount[i] += banknotesCount[i];
        }
    }
    
    std::vector<int> withdraw(int amount)
    {
        std::vector<int> res(5);

        for (auto i = 4; i >= 0; i--)
        {
            if (banknotesCount[i] == 0)
            {
                continue;
            }

            const auto t = std::min(amount / vals[i], banknotesCount[i]);

            res[i] = t;
            amount -= t * vals[i];
        }

        if (amount > 0)
        {
            return { -1 };
        }

        for (auto i = 0; i < 5; i++)
        {
            banknotesCount[i] -= res[i];
        }

        return res;
    }

private:
    std::vector<long long> banknotesCount;
    std::vector<long long> vals;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */