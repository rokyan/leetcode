// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers
{
public:
    ProductOfNumbers()
    {
    }
    
    void add(int num)
    {
        if (num == 0)
        {
            mult.clear();
        }
        else
        {
            if (mult.empty())
            {
                mult.push_back(num);
            }
            else
            {
                mult.push_back(mult.back());
                mult.back() *= num;
            }
        }
    }
    
    int getProduct(int k)
    {
        if (k <= std::size(mult))
        {
            return mult.back() / (k == std::size(mult) ? 1 : mult[std::size(mult) - k - 1]);
        }
        
        return 0;
    }
    
private:
    std::vector<int> mult;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */