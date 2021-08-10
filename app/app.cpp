#include "../include/mycomplex/mycomplex.hpp"
#include <iostream>

int main(){

    Complex a(13, 1);
    std::cout << "Number A: ";
    a.show_complex_algebraic();
    std::cout << std::endl;

    Complex b(7, -6);
    std::cout << "Number B: ";
    b.show_complex_algebraic();
    std::cout << std::endl;

    Complex c = a + b;
    std::cout << "Number C = A + B: ";
    c.show_complex_algebraic();
    std::cout << std::endl;

    c = a - b;
    std::cout << "Number C = A - B: ";
    c.show_complex_algebraic();
    std::cout << std::endl;

    c = a * b;
    std::cout << "Number C = A * B: ";
    c.show_complex_algebraic();
    std::cout << std::endl;

    c = a / b;
    std::cout << "Number C = A / B: ";
    c.show_complex_algebraic();
    std::cout << std::endl;

    std::cout << "Number c = A^5: ";
    c = a.pow_complex(5);
    c.show_complex_algebraic();
    std::cout << std::endl;

    std::cout << "Check a == b: ";
    a == b;
    std::cout << std::endl;

    std::cout << "Print trigonometric form of number C: ";
    c.show_complex_trigonometric();
    std::cout << std::endl;

    std::cout << "Show module of number C: ";
    double module_complex = c.module_complex();
    std::cout << module_complex << std::endl;

    return 0;
}
