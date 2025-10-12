// https://leetcode.com/problems/design-snake-game/description/

class SnakeGame
{
public:
    SnakeGame(int width, int height, vector<vector<int>>& food)
        : width{width}
        , height{height}
        , food{std::move(food)}
        , snake{{0, 0}}
    {
    }
    
    int move(const std::string& direction)
    {
        int nr = r;
        int nc = c;

        if (direction == "U")
        {
            nr--;
        }
        else if (direction == "D")
        {
            nr++;
        }
        else if (direction == "L")
        {
            nc--;
        }
        else if (direction == "R")
        {
            nc++;
        }

        if (nr < 0 || nr == height || nc < 0 || nc == width)
        {
            return -1;
        }

        const bool hasFood = points < std::size(food) &&
            food[points][0] == nr && food[points][1] == nc;

        if (hasFood)
        {
            points++;
            snake.emplace_back(nr, nc);
        }
        else
        {
            snake.pop_front();

            for (const auto [sr, sc] : snake)
            {
                if (nr == sr && nc == sc)
                {
                    return -1;
                }
            }

            snake.emplace_back(nr, nc);
        }

        r = nr;
        c = nc;

        return points;
    }

private:
    int width;
    int height;
    std::vector<std::vector<int>> food;
    int r = 0;
    int c = 0;
    std::deque<std::pair<int, int>> snake;
    int points = 0;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */