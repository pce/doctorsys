cmake_minimum_required(VERSION 3.13)
project(doctorsys)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(doctorsys ${SOURCES})

set(CMAKE_CXX_STANDARD 17)
set_property(TARGET doctorsys PROPERTY CXX_STANDARD 17)
target_link_libraries(doctorsys ${CURSES_LIBRARIES})

# TODO: add fs on Mac/clang
# target_link_libraries(doctorsys stdc++fs)

# TODO: Run -Werror in CI.
target_compile_options(doctorsys PRIVATE -Wall -Wextra)