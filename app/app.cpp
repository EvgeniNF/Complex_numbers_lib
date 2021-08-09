//
// Created by kandi on 06.08.2021.
//

#include "../include/mycomplex/mycomplex.hpp"
#include <iostream>

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

    return 0;
}