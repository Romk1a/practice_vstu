# Добавление всех cpp файлов из текущего каталога в библиотеку
add_library(rectangle_library rectangle.cpp rectangle.h)

# Указание пути к заголовочным файлам для этой библиотеки
target_include_directories(rectangle_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
