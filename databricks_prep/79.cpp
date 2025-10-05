class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        const int n = std::size(board);
        const int m = std::size(board.front());
        
        visited.resize(n);        
        for (auto& e : visited) e.resize(m);
        
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (search(board, x, y, n, m, word))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool search(const std::vector<std::vector<char>>& board, int x, int y, int n, int m, const std::string& word, int pos = 0)
    {
        if (x < 0 || x == n || y < 0 || y == m || visited[x][y])
        {
            return false;
        }
        
        if (word[pos] != board[x][y])
        {
            return false;
        }
        
        if (pos == std::size(word) - 1)
        {
            return true;
        }
        
        visited[x][y] = true;
        
        auto found = search(board, x - 1, y, n, m, word, pos + 1) ||
            search(board, x + 1, y, n, m, word, pos + 1) ||
            search(board, x, y - 1, n, m, word, pos + 1) ||
            search(board, x, y + 1, n, m, word, pos + 1);
        
        visited[x][y] = false;
        
        return found;
    }
    
private:
    std::vector<std::vector<bool>> visited;
};