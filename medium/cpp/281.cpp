// https://leetcode.com/problems/zigzag-iterator/description/

class ZigzagIterator
{
private:
    using iterType = std::vector<int>::iterator;

public:
    ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2)
        : p1{std::begin(v1)}
        , end1{std::end(v1)}
        , p2{std::begin(v2)}
        , end2{std::end(v2)}
    {
    }

    int next()
    {
        if (p1 != end1 && p2 != end2)
        {
            first ^= true;
            return first ? *p1++ : *p2++;
        }

        return p1 != end1 ? *p1++ : *p2++;
    }

    bool hasNext() const noexcept
    {
       return p1 != end1 || p2 != end2; 
    }

private:
    iterType p1;
    iterType end1;
    iterType p2;
    iterType end2;
    bool first = false;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */