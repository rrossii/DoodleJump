cmake_minimum_required (VERSION 3.6)
project(Framework VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Release)

set(MY_LIBNAME Framework)

find_library(SDL2 NAMES "SDL2")
find_library(SDL2main NAMES "SDL2main")
find_library(SDL2_image NAMES "SDL2_image")

include_directories(include)

add_library(${MY_LIBNAME} SHARED ./src/launch.cpp)
set_target_properties(${MY_LIBNAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${MY_LIBNAME} PROPERTIES PUBLIC_HEADER include/Framework/Framework.h)

install (TARGETS ${MY_LIBNAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)
