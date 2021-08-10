//
// Created by User on 05.08.2021.
//
#include "../mycomplex/mycomplex.hpp"
#include <iostream>
#include <cmath>


Complex::Complex(Complex &complex) : exception(complex) {
    complex.set_imag(this->get_imag());
    complex.set_real(this->get_real());
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
    double f = this->angle_f();
    std::cout << module << " * ";
    std::cout << "(cos(" << f << ") + i*sin(" << f << "))" << std::endl;
    /*if (this->_imag == 0 && this->_real > 0) {
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
    */
}

double Complex::module_complex() const {
    double module = pow(this->_real, 2) + pow(this->_imag, 2);
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
    double real = (this->get_real() * complex.get_real()) + (this->get_imag() * complex.get_imag()) * -1;
    double imag = (this->get_imag() * complex.get_real()) + (this->get_real() * complex.get_imag());
    return Complex(real, imag);
}

Complex Complex::operator/(const Complex &complex) const {
    double divider = pow(complex.get_real(), 2) - pow(complex.get_imag(), 2) * -1;
    double real = (this->get_real() * complex.get_real()) + (this->get_imag() * complex.get_imag() * -1) * -1;
    double imag = (this->get_imag() * complex.get_real()) + (this->get_real() * complex.get_imag() * -1);
    real /= divider;
    imag /= divider;
    return Complex(real, imag);
}

void Complex::err_comparison() {
    try{
        throw std::exception("Complex numbers cannot be compared");
    }
    catch (const std::exception& error){
        std::cout << "Error: " << error.what() << std::endl;
    }
}

std::vector<unsigned long> Complex::pascal_triangle(unsigned int n) {
    std::vector<unsigned long> c ={};
    c.resize(n + 1);
    // Обнуляем вектор
    for (unsigned int i = 0; i <= n; i++){
        c.at(i) = 0;
    }
    // 0 степень треугольника
    c.at(0) = 1;
    // Вычисляем коэффициенты перемещаясь сверху вниз
    for (unsigned int j = 0; j <= n; j++){
        for (unsigned int i = j; i >= 1; --i){
            c.at(i) = c.at(i - 1) + c.at(i);
        }
    }
    return c;
}

Complex Complex::pow_complex(int n) {
    std::vector<unsigned long> triangle = this->pascal_triangle(static_cast<unsigned int>(n));
    double pow_real = 0;
    double pow_imag = 0;
    for (int i = 0; i <= n; i++){
        if (i % 2 == 0){
            if ((i / 2) % 2 == 0){
                pow_real += triangle.at(i) * (pow(this->get_real(), n - i) * pow(this->get_imag(), i));
            }
            else {
                pow_real += triangle.at(i) * (pow(this->get_real(), n - i) * pow(this->get_imag(), i) * -1);
            }
        }
        else {
            if ((i / 2) % 2 == 0){
                pow_imag += triangle.at(i) * (pow(this->get_real(), n - i) * pow(this->get_imag(), i));
            }
            else {
                pow_imag += triangle.at(i) * (pow(this->get_real(), n - i) * pow(this->get_imag(), i) * -1);
            }
        }
    }
    return Complex(pow_real, pow_imag);
}

double Complex::angle_f() const {
    if (this->_real == 0 && this->_imag >= 0){
        return .0;
    }
    else if (this->_imag == 0 && this->_real < 0){
        return 180.0;
    }
    else if (this->_imag > 0 && this->_real == 0) {
        return 90.0;
    }
    else if(this->_imag < 0 && this->_real == 0){
        return -90.0;
    }
    else if (this->_real > 0 && this->_imag > 0 || this->_real < 0 && this->_imag < 0){
        return atan(this->_real / this->_imag) * 180/3.14;
    }
    else if (this->_real > 0 && this->_imag < 0 || this->_real < 0 && this->_imag > 0){
        return atan((this->_real / this->_imag) * (-1)) * 180/3.14;
    }
    return .0;
}



