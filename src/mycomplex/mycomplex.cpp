//
// Created by kandi on 06.08.2021.
//
#include "../mycomplex/mycomplex.hpp"
#include <iostream>
#include <cmath>


Complex::Complex(Complex &complex){
    //std::cout << "It's copy" << std::endl;
}

Complex::Complex(Complex &&complex) noexcept {
    //std::cout << "It's move" << std::endl;
}

Complex::Complex(double real, double imag) {
    this->_real = real;
    this->_imag = imag;
}

void Complex::set_real(double real) {
    this->_real = real;
}

void Complex::set_imag(double imag) {
    this->_imag = imag;
}

void Complex::show_complex_algebraic() const {
    std::cout << this->_real;
    std::cout << std::showpos << this->_imag << std::noshowpos << "i" << std::endl;
}

void Complex::show_complex_trigonometric() const {
    if (this->_real == 0 && this->_imag == 0){
        std::cout << "This number has no trigonometric form" << std::endl;
        return;
    }
    double module = this->module_complex();
    std::cout << module << " * ";
    if (this->_imag == 0 && this->_real > 0) {
        std::cout << "(cos(0) + i*sin(0))" << std::endl;
    }
    else if (this->_imag == 0 && this->_real < 0){
        std::cout << "(cos(180) + i*sin(180))" << std::endl;
    }
    else if (this->_imag > 0 && this->_real == 0) {
        std::cout << "(cos(90) + i*sin(90))" << std::endl;
    }
    else if(this->_imag < 0 && this->_real == 0){
        std::cout << "(cos(-90) + i*sin(-90))" << std::endl;
    }
    else if (this->_real > 0 && this->_imag > 0){
        double f = atan(this->_real / this->_imag) * 180/3.14;
        std::cout << "(cos(" << f << ") + i*sin(" << f << "))" << std::endl;
    }
    else if (this->_real > 0 && this->_imag < 0){
        double f = atan((this->_real / this->_imag) * (-1)) * 180/3.14;
        std::cout << "(cos(" << f << ") + i*sin(" << f << "))" << std::endl;
    }
    else if (this->_real < 0 && this->_imag < 0){
        double f = atan(this->_real / this->_imag) * 180/3.14;
        std::cout << "(cos(-180 + " << f << ") + i*sin(-180 + " << f << "))" << std::endl;
    }
    else if(this->_real < 0 && this->_imag > 0){
        double f = atan((this->_real / this->_imag) * (-1)) * 180/3.14;
        std::cout << "(cos(180 - " << f << ") + i*sin(180 - " << f << "))" << std::endl;
    }
}

double Complex::module_complex() const {
    auto module = static_cast<double>(pow(this->_real, 2) + pow(this->_imag, 2));
    module = sqrt(module);
    return module;
}

double Complex::get_real() const {
    return this->_real;
}

double Complex::get_imag() const {
    return this->_imag;
}

Complex Complex::operator+ (const Complex& complex) const {
    return Complex(this->get_real() + complex.get_real(),
                   this->get_imag() + complex.get_imag());
}

Complex Complex::operator-(const Complex &complex) const {
    return Complex(this->get_real() + (complex.get_real() * -1),
                   this->get_imag() + (complex.get_imag() * -1));
}

Complex& Complex::operator=(const Complex& complex) {
    this->set_real(complex.get_real());
    this->set_imag(complex.get_imag());
    return *this;
}

Complex Complex::operator*(const Complex &complex) const {
    double real = 0;
    double imag = 0;
    real = (this->get_real() * complex.get_real()) + (this->get_imag() * complex.get_imag()) * -1;
    imag = (this->get_imag() * complex.get_real()) + (this->get_real() * complex.get_imag());
    return Complex(real, imag);
}

Complex Complex::operator/(const Complex &complex) const {
    double real = 0;
    double imag = 0;
    double divider = 0;
    divider = pow(complex.get_real(), 2) - pow(complex.get_imag(), 2) * -1;
    real = (this->get_real() * complex.get_real()) + (this->get_imag() * complex.get_imag() * -1) * -1;
    imag = (this->get_imag() * complex.get_real()) + (this->get_real() * complex.get_imag() * -1);
    real /= divider;
    imag /= divider;
    return Complex(real, imag);
}

void Complex::err_comparison() {
    throw std::runtime_error("Comparison of complex numbers is not possible");
}

