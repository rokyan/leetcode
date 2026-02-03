// https://leetcode.com/problems/apply-discount-every-n-orders/description/

class Cashier
{
public:
    Cashier(int n, int discount, const std::vector<int>& products, const std::vector<int>& prices)
        : n{n}
        , discount{discount}
    {
        for (int i = 0; i < products.size(); i++)
        {
            data.emplace(products[i], prices[i]);
        }
    }
    
    double getBill(const std::vector<int>& products, const std::vector<int>& amount)
    {
        id = (id + 1) % n;

        double res = 0.0;

        for (int i = 0; i < products.size(); i++)
        {
            res += amount[i] * data[products[i]];
        }

        if (id == 0)
        {
            res *= (100.0 - discount) / 100.0;
        }

        return res;
    }

private:
    int n{0};
    int discount{0};
    unsigned id{0};
    std::unordered_map<int, int> data;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */