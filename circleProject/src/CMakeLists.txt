# Добавление всех cpp файлов из текущего каталога в библиотеку
add_library(circle_library circle.cpp circle_h.h)

# Указание пути к заголовочным файлам для этой библиотеки
target_include_directories(circle_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
