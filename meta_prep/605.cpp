class Solution
{
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
    {
        auto cnt = 0;

        for (auto i = 0; i < std::size(flowerbed) && cnt < n; i++)
        {
            if (i == 0 || flowerbed[i - 1] == 0)
            {
                if (i + 1 == std::size(flowerbed) || flowerbed[i + 1] == 0)
                {
                    if (flowerbed[i] == 0)
                    {
                        flowerbed[i] = 1;
                        cnt++;
                    }
                    
                }
            }
        }

        return cnt == n;
    }
};