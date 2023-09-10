// https://leetcode.com/problems/design-bitset/description/

class Bitset
{
private:
    static constexpr std::size_t bits_per_element = 64;

public:
    Bitset(int size)
        : size{ static_cast<std::size_t>(size) }
        , ones{ 0 }
        , flipped{ false }
    {
        data.resize((size * bits_per_element + bits_per_element - 1) / bits_per_element);   
    }
    
    void fix(int idx)
    {
        if (flipped)
        {
            if (check(idx))
            {
                ones--;
            }

            data[idx / bits_per_element] &= ~(1ULL << (idx % bits_per_element));
        }
        else
        {
            if (!check(idx))
            {
                ones++;
            }

            data[idx / bits_per_element] |= 1ULL << (idx % bits_per_element);
        }
    }
    
    void unfix(int idx)
    {
        if (flipped)
        {
            if (!check(idx))
            {
                ones++;
            }

            data[idx / bits_per_element] |= 1ULL << (idx % bits_per_element);
        }
        else
        {
            if (check(idx))
            {
                ones--;
            }

            data[idx / bits_per_element] &= ~(1ULL << (idx % bits_per_element));   
        }
    }
    
    void flip()
    {
        flipped ^= true;
    }
    
    bool all()
    {
        return flipped ? ones == 0 : ones == size;
    }
    
    bool one()
    {
        return flipped ? ones < size : ones > 0;
    }
    
    int count()
    {
        return flipped ? size - ones : ones;
    }
    
    std::string toString()
    {
        std::string serialized(size, '0');

        for (auto idx = 0; idx < size; idx++)
        {
            if (check(idx) ^ flipped)
            {
                serialized[idx] = '1';
            }
        }

        return serialized;
    }

private:
    bool check(int idx) const
    {
        return ((data[idx / bits_per_element] & (1ULL << (idx % bits_per_element))) != 0);
    }

private:
    std::size_t size;
    std::size_t ones;
    bool flipped;
    std::vector<std::uint64_t> data;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */