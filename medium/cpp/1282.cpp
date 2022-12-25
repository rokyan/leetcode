// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

class Solution
{
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes)
    {
        const int n = size(groupSizes);
        
        std::vector<std::pair<int, int>> people(n);
       
        for (int i = 0; i < n; i++)
        {
            people[i] = { groupSizes[i], i };
        }
        
        std::sort(begin(people), end(people));
        
        std::vector<std::vector<int>> answer;
        
        for (int i = 0; i < n; )
        {
            auto groupSize = people[i].first;
            std::vector<int> group(groupSize);

            for (int j = i; j < i + groupSize; j++)
            {
                group[j - i] = people[j].second;
            }
            
            answer.push_back(group);
            i += groupSize;
        }
        
        return answer;
    }
};