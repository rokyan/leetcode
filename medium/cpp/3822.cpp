// https://leetcode.com/problems/design-order-management-system/description/

class OrderManagementSystem
{
private:
    enum class OrderType { Buy, Sell };

    struct Order
    {
        Order() = default;

        Order(int id, OrderType type, int price)
            : id{id}
            , type{type}
            , price{price}
        {}

        int id{0};
        OrderType type{OrderType::Buy};
        int price{0};
    };

public:
    OrderManagementSystem() = default;
    
    void addOrder(int orderId, const std::string& orderType, int price)
    {
        orders.emplace(orderId,
            Order(orderId, toOrderType(orderType), price));
        getOrderIdsByType(toOrderType(orderType))[price].insert(orderId);
    }
    
    void modifyOrder(int orderId, int newPrice)
    {
        getOrderIdsByType(orders[orderId].type)[orders[orderId].price].erase(orderId);
        orders[orderId].price = newPrice;
        getOrderIdsByType(orders[orderId].type)[orders[orderId].price].insert(orderId);
    }
    
    void cancelOrder(int orderId)
    {
        getOrderIdsByType(orders[orderId].type)[orders[orderId].price].erase(orderId);
        orders.erase(orderId);
    }
    
    std::vector<int> getOrdersAtPrice(const std::string& orderType, int price)
    {
        const auto& orderIdsByType = getOrderIdsByType(toOrderType(orderType));

        if (const auto it = orderIdsByType.find(price); it != orderIdsByType.end())
        {
            return std::vector<int>(it->second.cbegin(), it->second.cend());
        }

        return {};
    }

private:
    OrderType toOrderType(const std::string& type)
    {
        if (type == "buy")
        {
            return OrderType::Buy;
        }
        else
        {
            return OrderType::Sell;
        }
    }

    std::unordered_map<int, std::unordered_set<int>>& getOrderIdsByType(OrderType type)
    {
        return type == OrderType::Buy ? buyOrderIdsByPrice : sellOrderIdsByPrice;
    }

private:
    std::unordered_map<int, Order> orders;
    std::unordered_map<int, std::unordered_set<int>> buyOrderIdsByPrice;
    std::unordered_map<int, std::unordered_set<int>> sellOrderIdsByPrice;
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */