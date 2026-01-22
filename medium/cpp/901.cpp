// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner
{
public:
    StockSpanner() = default;
    
    int next(int price)
    {
        while (!st.empty() && st.back().first <= price)
        {
            st.pop_back();
        }

        const int res = st.empty() ? id : id - st.back().second;

        st.emplace_back(price, id);
        id++;

        return res;
    }

private:
    std::vector<std::pair<int, int>> st;
    int id{1};
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */