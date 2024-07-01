# ”кажите исходные файлы
set(SOURCES circle.cpp)

# —оздайте библиотеку
add_library(CircleLibrary ${SOURCES})

# ”кажите заголовочные файлы
target_include_directories(CircleLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
