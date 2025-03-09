/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 #include <ranges>

class NestedIterator
{
public:
    NestedIterator(std::vector<NestedInteger> &nestedList)
    {
        std::copy(std::rbegin(nestedList), std::rend(nestedList), std::back_inserter(data));
    }
    
    int next()
    {
        return next_val;
    }
    
    bool hasNext()
    {
        return move_to_next();
    }

private:
    bool move_to_next()
    {
        if (data.empty())
        {
            return false;
        }

        auto first = data.back();
        data.pop_back();

        if (first.isInteger())
        {
            next_val = first.getInteger();
            return true;
        }
        else
        {
            const auto& elements = first.getList();

            for (auto e : elements | std::views::reverse)
            {
                data.push_back(e);
            }

            return move_to_next();
        }
    }

private:
    std::vector<NestedInteger> data;
    int next_val = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */