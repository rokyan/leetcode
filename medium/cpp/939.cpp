// https://leetcode.com/problems/minimum-area-rectangle/

class Solution
{
public:
    int minAreaRect(std::vector<std::vector<int>>& points)
    {
        std::sort(std::begin(points), std::end(points), [](const auto& left_point, const auto& right_point) {
            return left_point[0] < right_point[0] || left_point[0] == right_point[0] && left_point[1] < right_point[1];
        });
        
        std::vector<std::pair<int, std::vector<int>>> compressed;
        compressed.reserve(std::size(points));
        
        for (const auto& point : points)
        {
            if (compressed.empty() || compressed.back().first != point[0])
            {
                compressed.push_back({ point[0], { point[1] }});
            }
            else
            {
                compressed.back().second.push_back(point[1]);
            }
        }
        
        const std::size_t n = std::size(compressed);
        
        int ans = 0;
        
        for (std::size_t i = 0; i + 1 < n; i++)
        {
            for (std::size_t j = i + 1; j < n; j++)
            {
                int last = -1;
                
                std::size_t i_pt = 0;
                std::size_t j_pt = 0;
                
                const auto& yi = compressed[i].second;
                const auto& yj = compressed[j].second;
                
                while (i_pt < std::size(yi) && j_pt < std::size(yj))
                {
                    while (i_pt < std::size(yi) && yi[i_pt] < yj[j_pt])
                    {
                        i_pt++;
                    }
                    
                    if (i_pt == std::size(yi))
                    {
                        break;
                    }
                    
                    while (j_pt < std::size(yj) && yj[j_pt] < yi[i_pt])
                    {
                        j_pt++;
                    }
                    
                    if (j_pt == std::size(yj))
                    {
                        break;
                    }
                    
                    if (yi[i_pt] == yj[j_pt])
                    {
                        if (last != -1)
                        {
                            const auto area = (compressed[j].first - compressed[i].first) * (yi[i_pt] - last);
                            
                            ans = (ans == 0) ? area : std::min(ans, area);
                        }
                        
                        last = yi[i_pt];
                        
                        i_pt++;
                        j_pt++;
                    }
                }
            }
        }
        
        return ans;
    }
};