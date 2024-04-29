// https://leetcode.com/problems/flatten-2d-vector/description/

class Vector2D
{
public:
    Vector2D(std::vector<std::vector<int>>& vec)
        : iter{ std::cbegin(vec) }
        , end_iter{ std::cend(vec) }
    {
        init_sub_iter();
    }
    
    int next()
    {
        const auto val = *sub_iter;
        advance();
        return val;
    }
    
    bool hasNext()
    {
        return iter != end_iter;
    }

private:
    void init_sub_iter()
    {
        while (iter != end_iter && iter->empty())
        {
            ++iter;
        }

        if (iter != end_iter)
        {
            sub_iter = std::cbegin(*iter);
        }
    }

    void advance()
    {
        if (++sub_iter == std::cend(*iter))
        {
            ++iter;
            init_sub_iter();
        }
    }

private:
    std::vector<std::vector<int>>::const_iterator iter;
    std::vector<std::vector<int>>::const_iterator end_iter;
    std::vector<int>::const_iterator sub_iter;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */