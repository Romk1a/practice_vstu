add_library(circle_library circle.cpp circle_h.h)

target_include_directories(circle_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
