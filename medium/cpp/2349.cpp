// https://leetcode.com/problems/design-a-number-container-system/description/

class NumberContainers
{
public:
    NumberContainers()
    {  
    }
    
    void change(int index, int number)
    {
        if (auto it = arr.find(index); it != std::end(arr))
        {
            const auto old = it->second;
            data[old].erase(index);
        }

        arr[index] = number;
        data[number].insert(index);
    }
    
    int find(int number)
    {
        if (auto it = data.find(number); it != std::end(data))
        {
            return it->second.empty() ? -1 : *std::begin(it->second);
        }

        return -1;
    }

private:
    std::unordered_map<int, int> arr;
    std::unordered_map<int, std::set<int>> data;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */