// https://leetcode.com/problems/simple-bank-system/

class Bank
{
public:
    Bank(std::vector<long long>& balance)
        : balance(balance)
    {
        
    }
    
    bool transfer(int account1, int account2, long long money)
    {
        if (!validate_account(account1) || !validate_account(account2))
        {
            return false;
        }
        
        if (money > balance[account1 - 1])
        {
            return false;
        }
        
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        
        return true;
    }
    
    bool deposit(int account, long long money)
    {
        if (!validate_account(account))
        {
            return false;
        }
        
        balance[account - 1] += money;
        
        return true;
    }
    
    bool withdraw(int account, long long money)
    {
        if (!validate_account(account))
        {
            return false;
        }
        
        if (money > balance[account - 1])
        {
            return false;
        }
        
        balance[account - 1] -= money;
        
        return true;
    }
    
private:
    bool validate_account(int account) const noexcept
    {
        return account > 0 && account <= std::size(balance);
    }
    
private:
    std::vector<long long> balance;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */