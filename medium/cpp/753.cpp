// https://leetcode.com/problems/asteroid-collision/description/

class Solution
{
public:
    std::vector<int> asteroidCollision(const std::vector<int>& asteroids)
    {
        std::vector<int> st;

        for (auto a : asteroids)
        {
            if (a > 0)
            {
                st.push_back(a);
            }
            else
            {
                while (!st.empty() && st.back() > 0)
                {
                    if (st.back() + a < 0)
                    {
                        st.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }

                if (!st.empty() && st.back() + a == 0)
                {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0)
                {
                    st.push_back(a);
                }
            }
        }

        return st;
    }
};