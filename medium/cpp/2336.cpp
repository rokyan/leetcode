// https://leetcode.com/problems/smallest-number-in-infinite-set/description/

class SmallestInfiniteSet
{
public:
    SmallestInfiniteSet()
        : smallest(1)
    {
        
    }
    
    int popSmallest()
    {
        if (!added.empty())
        {
            const auto it = std::cbegin(added);
            const auto num = *it;
            added.erase(it);
            return num;
        }

        return smallest++;
    }
    
    void addBack(int num)
    {
        if (num < smallest)
        {
            added.insert(num);
        }
    }

private:
    int smallest;
    std::set<int> added;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */