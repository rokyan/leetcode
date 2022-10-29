// https://leetcode.com/problems/complex-number-multiplication/

class Solution
{
private:
    class complex
    {
        public:
            complex(int real, int img)
                : real(real)
                , img(img)
            {}
        
            complex(const std::string& s)
            {
                parse(s);
            }
        
            operator std::string() const
            {
                return std::to_string(real) + "+" + std::to_string(img) + "i";
            }
        
            friend complex operator*(const complex& x, const complex& y)
            {
                return complex(x.real * y.real - x.img * y.img, x.real * y.img + x.img * y.real);
            }
        
        private:
            void parse(const std::string& s)
            {
                const auto pos = s.find('+');

                real = std::stoi(s.substr(0, pos));
                img = std::stoi(s.substr(pos + 1));
            }
        
        private:
            int real;
            int img;
    };
    
public:
    std::string complexNumberMultiply(std::string num1, std::string num2) 
    {
        const auto res = complex(num1) * complex(num2);
        return res;
    }
};