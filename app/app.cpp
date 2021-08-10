#include "../include/mycomplex/mycomplex.hpp"
#include <iostream>

class Val{
public:
    explicit Val(int i){
        this->_i = i;
    }
    Val(Val& val){

    }
    Val(Val&& val) noexcept {

    }
private:
    int _i{};
};

int main(){

    Complex a(13, 1);
    std::cout << "Number A:" << std::endl;
    a.show_complex_algebraic();

    Complex b(7, -6);
    std::cout << "Number B:" << std::endl;
    b.show_complex_algebraic();

    Complex c = a + b;
    std::cout << "Number C = A + B:" << std::endl;
    c.show_complex_algebraic();

    c = a - b;
    std::cout << "Number C = A - B:" << std::endl;
    c.show_complex_algebraic();

    c = a * b;
    std::cout << "Number C = A * B:" << std::endl;
    c.show_complex_algebraic();

    c = a / b;
    std::cout << "Number C = A / B:" << std::endl;
    c.show_complex_algebraic();

    try{
        a == b;
    }
    catch (const std::exception& err){
        std::cout << err.what() << std::endl;
    }
    c.set_real(-3);
    c.set_imag(-1);
    c = c.pow_complex(3);
    c.show_complex_algebraic();
    return 0;
}
