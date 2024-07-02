# Добавление всех cpp файлов из текущего каталога в библиотеку
add_library(trapezoid_library trapezoid.cpp trapezoid.h)

# Указание пути к заголовочным файлам для этой библиотеки
target_include_directories(trapezoid_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
