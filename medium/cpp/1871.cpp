// https://leetcode.com/problems/jump-game-vii/

class Solution
{
public:
    bool canReach(std::string s, int minJump, int maxJump)
    {
        std::vector<int> visited(std::size(s));
        
        visited[0] = true;
        
        std::size_t left = 0;
        std::size_t right = 1;
        
        while (left < std::size(visited) && !visited.back())
        {
            if (s[left] == '0' && visited[left])
            {
                right = std::max(right, left + minJump);
                
                while (right <= std::min(left + maxJump, std::size(visited) - 1))
                {
                    if (s[right] == '0')
                    {
                        visited[right] = true;
                    }
                    
                    right++;
                }
            }
            
            left++;
        }
        
        return visited.back();
    }
};