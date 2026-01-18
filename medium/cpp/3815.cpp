// https://leetcode.com/problems/design-auction-system/description/

class AuctionSystem
{
private:
    class BidsCollection final
    {
    public:
        void add(int userId, int bidAmount)
        {
            clear(userId);
            insertToOrdered(userId, bidAmount);
            setLatest(userId, bidAmount);
        }

        void update(int userId, int bidAmount)
        {
            add(userId, bidAmount);
        }

        void remove(int userId)
        {
            removeFromOrdered(userId, getLatest(userId));
            clear(userId);
        }

        int getHighest()
        {
            if (ordered.empty())
            {
                return -1;
            }

            return ordered.begin()->second;
        }

    private:
        void clear(int userId)
        {
            if (const auto it = latest.find(userId); it != latest.end())
            {
                const int bid = it->second;
                ordered.erase({bid, userId});
            }
        }

        void setLatest(int userId, int bid)
        {
            latest[userId] = bid;
        }

        int getLatest(int userId)
        {
            return latest[userId];
        }

        void insertToOrdered(int userId, int bid)
        {
            ordered.emplace(bid, userId);
        }

        void removeFromOrdered(int userId, int bid)
        {
            ordered.erase({bid, userId});
        }

    private:
        std::set<std::pair<int, int>, std::greater<>> ordered;
        std::unordered_map<int, int> latest;
    };

public:
    AuctionSystem() = default;
    
    void addBid(int userId, int itemId, int bidAmount) 
    {
        getBids(itemId).add(userId, bidAmount);
    }
    
    void updateBid(int userId, int itemId, int newAmount)
    {
        getBids(itemId).update(userId, newAmount);
    }
    
    void removeBid(int userId, int itemId)
    {
        getBids(itemId).remove(userId);
    }
    
    int getHighestBidder(int itemId)
    {
        return getBids(itemId).getHighest();
    }

private:
    BidsCollection& getBids(int itemId)
    {
        return bidsPerItem[itemId];
    }

private:
    std::unordered_map<int, BidsCollection> bidsPerItem;
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */