#include <iostream>
template <class type>
class RGB {
public:
    type input;

    RGB(type _input) {
        input = _input;
    }

    int rgb(double _input) {

    }
};


int main() {
    {
        RGB<double> rgb(0.5);
        std::cout << rgb << std::endl;
        std::cout << rgb + 0.3 << std::endl;
        std::cout << rgb + 0.3 + RGB<double>(0.5, 0.1, 0.1) << std::endl;
    }
    {
        RGB<int> rgb(130);
        std::cout << rgb << std::endl;
        std::cout << rgb + 60 << std::endl;
        std::cout << rgb + 60 + RGB<int>(100, 30, 30) << std::endl;
    }
}
