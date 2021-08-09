# Установка имени проекта
set(PROJECT application)

set(SERVER ${PROJECT})
set(SERVER_SOURCE app.cpp)

# Добавление выполняемого файла
add_executable(${SERVER}
        ${SERVER_SOURCE})

target_link_libraries(${SERVER} my_complex)