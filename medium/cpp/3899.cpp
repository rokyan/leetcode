// https://leetcode.com/problems/angles-of-a-triangle/description/

class Solution
{
public:
    std::vector<double> internalAngles(std::vector<int>& sides)
    {
        std::ranges::sort(sides);

        int a = sides[0];
        int b = sides[1];
        int c = sides[2];
        
        if (a + b <= c)
        {
            return {};
        }
        
        double cosA = (1.0 * b * b + 1.0 * c * c - 1.0 * a * a) / (2.0 * b * c);
        double cosB = (1.0 * a * a + 1.0 * c * c - 1.0 * b * b) / (2.0 * a * c);
        
        double A = acos(cosA) * 180.0 / acos(-1.0);
        double B = acos(cosB) * 180.0 / acos(-1.0);
        double C = 180.0 - A - B;

        return {A, B, C};
    }
};