// https://leetcode.com/problems/design-memory-allocator/description/

class Allocator
{
public:
    Allocator(int n)
        : n(n)
        , data(n)
    {
        
    }
    
    int allocate(int size, int mID)
    {
        auto cnt = 0;

        for (auto i = 0; i < n; i++)
        {
            if (data[i] != 0)
            {
                cnt = 0;
            }
            else
            {
                cnt++;

                if (cnt == size)
                {
                    const auto start = i - cnt + 1;

                    for (auto j = start; j <= i; j++)
                    {
                        data[j] = mID;
                    }

                    return start;
                }
            }
        }

        return -1;
    }
    
    int free(int mID)
    {
        auto cnt = 0;

        for (auto i = 0; i < n; i++)
        {
            if (data[i] == mID)
            {
                cnt++;
                data[i] = 0;
            }
        }

        return cnt;
    }

private:
    int n;
    std::vector<int> data;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */