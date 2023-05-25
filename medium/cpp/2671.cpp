// https://leetcode.com/problems/frequency-tracker/description/

class FrequencyTracker
{
public:
    void add(int number)
    {
        if (const auto it = cnt.find(number); it != std::end(cnt))
        {
            freq[it->second]--;
            it->second++;
            freq[it->second]++;
        }
        else
        {
            cnt.emplace(number, 1);
            freq[1]++;
        }
    }
    
    void deleteOne(int number)
    {
        if (const auto it = cnt.find(number); it != std::end(cnt))
        {
            freq[it->second]--;
            it->second--;

            if (it->second > 0)
            {
                freq[it->second]++;
            }
            else
            {
                cnt.erase(it);
            }
        }
    }
    
    bool hasFrequency(int frequency)
    {
        if (const auto it = freq.find(frequency); it != std::end(freq))
        {
            return it->second > 0;
        }

        return false;
    }

private:
    std::unordered_map<int, int> cnt;
    std::unordered_map<int, int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */