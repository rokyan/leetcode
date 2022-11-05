// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution
{
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs)
    {
        std::unordered_map<int, std::vector<int>> graph;
        
        for (const auto& edge : adjacentPairs)
        {
            const auto u = edge.front();
            const auto v = edge.back();
            
            const auto uit = graph.find(u);
            
            if (uit == std::cend(graph))
            {
                graph.insert({ u, { v } });
            }
            else
            {
                uit->second.push_back(v);
            }
            
            const auto vit = graph.find(v);
            
            if (vit == std::cend(graph))
            {
                graph.insert({ v, { u } });
            }
            else
            {
                vit->second.push_back(u);
            }
        }
        
        std::vector<int> arr;
        arr.reserve(std::size(graph));
        
        std::unordered_set<int> used;
        
        int elem = 0;
        
        for (const auto& entry : graph)
        {
            if (std::size(entry.second) == 1)
            {
                elem = entry.first;
                break;
            }
        }
               
        used.insert(elem);
        arr.push_back(elem);
        
        while (std::size(used) < std::size(graph))
        {
            auto tos = graph[elem];
            
            for (auto to : tos)
            {
                if (used.find(to) == std::end(used))
                {
                    elem = to;
                    used.insert(elem);
                    arr.push_back(elem);
                    break;
                }
            }
        }
        
        return arr;
    }
};