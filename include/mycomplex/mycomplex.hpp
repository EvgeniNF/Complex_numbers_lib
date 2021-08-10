//
// Created by User on 05.08.2021.
//


#ifndef MATH_LIB_MYMATH_HPP
#define MATH_LIB_MYMATH_HPP

#include <iostream>
#include <vector>

class Complex : std::exception{
public:
    explicit Complex(double real = 0, double imag = 0);
    /* Конструктор
     * Создает комплексное число
     * @real - вещественная часть
     * @imag - мнимая часть
     */
    void set_real(double real);
    /* Set метод
     * Устанавливает действительную часть комплексного числа
     * @real - новая вещественная часть
     */
    void set_imag(double imag);
    /* Set метод
     * Устанавливает мнимую часть комплексного числа
     * @imag - новая мнимая часть
     */
    void show_complex_algebraic() const;
    /* Show метод
     * Выводит комплексное число в алгеброической форме в консоль
     */
    void show_complex_trigonometric() const;
    /* Show метод
     * Выводит комплексное число в тригонометрической форме в консоль
     */
    [[nodiscard]] double get_real() const;
    /* Get метод
     * Возвращает действительную часть комплексного числа
     */
    [[nodiscard]] double get_imag() const;
    /* Get метод
     * Возвращает мнимую часть комплексного числа
     */
    Complex& operator=(const Complex& complex);
    /* Оператор =
     * Функция присваивания
     * @complex - присваиваемое комплексное число
     */
    Complex operator+(const Complex& complex) const;
    /* Оператор +
     * Функция складывает два комплексных числа
     * @complex - второе слогаемое
     */
    Complex operator-(const Complex& complex) const;
    /* Оператор -
     * Функция вычитает два комплексных числа
     * @complex - вычитаемое число
     */
    Complex operator*(const Complex& complex) const;
    /* Оператор *
     * Функция умножает два комплексных числа
     * @complex - второй множитель
     */
    Complex operator/(const Complex& complex) const;
    /* Оператор /
     * Функция делит два числа
     * @complex - делитель
     */
    void operator<=(const Complex& complex)const { err_comparison(); }
    void operator>=(const Complex& complex)const { err_comparison(); }
    void operator>(const Complex& complex)const { err_comparison(); }
    void operator<(const Complex& complex)const { err_comparison(); }
    void operator==(const Complex& complex)const { err_comparison(); }
    /* Операторы <=, >=, ==, >, <
     * Функция вызывает исключение при выполнеия сравнений чисел
     * @complex - сравниваемое число
     */
    Complex pow_complex(int n);
    /* Функция
     * Возведение в степень
     * @n - Степень возведения
     */
    [[nodiscard]] double module_complex() const;
    /* Функция
     * Находит модуль комплексного числа
     */
    Complex(Complex &complex);
    Complex(Complex &&complex) noexcept;
    ~Complex() override = default;
private:
    static void err_comparison();
    /* Функция
     * Вызывает исключение
     */
    static std::vector<unsigned long> pascal_triangle(unsigned int n);
    /* Функция
     * Находит коэффициенты для бинома Ньютона
     * @n - Степень бинома
     */
    double _real{};  // Действительная часть комплексного числа
    double _imag{};  // Мнимая часть комплексного числа
};

#endif //MATH_LIB_MYMATH_HPP
