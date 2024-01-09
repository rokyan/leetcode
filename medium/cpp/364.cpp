// https://leetcode.com/problems/nested-list-weight-sum-ii/description/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    int depthSumInverse(std::vector<NestedInteger>& nestedList)
    {
        auto maxDepth = getDepth(nestedList.front());

        for (auto i = 1; i < std::size(nestedList); i++)
        {
            maxDepth = std::max(maxDepth, getDepth(nestedList[i]));
        }

        auto res = 0;

        for (const auto& e : nestedList)
        {
            res += calc(e, maxDepth);
        }

        return res;
    }

private:
    static int getDepth(const NestedInteger& nestedList, int depth = 1)
    {
        auto maxDepth = depth;

        for (const auto& e : nestedList.getList())
        {
            maxDepth = std::max(maxDepth, getDepth(e, depth + 1));
        }

        return maxDepth;
    }

    static int calc(const NestedInteger& nestedList, int maxDepth, int depth = 1)
    {
        if (nestedList.isInteger())
        {
            return nestedList.getInteger() * (maxDepth - depth + 1);
        }

        auto tot = 0;

        for (const auto& e : nestedList.getList())
        {
            tot += calc(e, maxDepth, depth + 1);
        }

        return tot;
    }
};