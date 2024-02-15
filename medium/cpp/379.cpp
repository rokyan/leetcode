// https://leetcode.com/problems/design-phone-directory/description/

class PhoneDirectory
{
public:
    PhoneDirectory(int maxNumbers)
        : n{ maxNumbers }
        , cur{ 0 }
    {
    }
    
    int get()
    {
        if (!free.empty())
        {
            auto res = *std::begin(free);
            free.erase(std::begin(free));
            return res;
        }
        else if (cur < n)
        {
            return cur++;
        }

        return -1;
    }
    
    bool check(int number)
    {
        if (free.find(number) != std::end(free))
        {
            return true;
        }

        if (number >= cur)
        {
            return true;
        }

        return false;
    }
    
    void release(int number)
    {
        if (number == cur - 1)
        {
            cur--;
        }
        else if (number < cur - 1)
        {
            free.insert(number);
        }
    }

private:
    int n;
    int cur;
    std::unordered_set<int> free;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */