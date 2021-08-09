  
# Установка версии Cmake
cmake_minimum_required(VERSION 3.14)

# Установка данных проекта
project(Complex_Numbers
        VERSION 0.1.0
        DESCRIPTION "My first lib in C++"
        LANGUAGES CXX)

# Подключение директорий
add_subdirectory(app)
add_subdirectory(src)
