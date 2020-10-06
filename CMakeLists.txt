cmake_minimum_required(VERSION 3.10)
project(doctorsys)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
# file(GLOB SOURCES "src/*.cpp")
SET(SOURCES src/file_util.cpp src/format.cpp src/main.cpp src/screen.cpp src/system.cpp)
IF(APPLE)
  SET(SOURCES ${SOURCES} src/system_darwin.cpp)
ENDIF(APPLE)

add_executable(doctorsys ${SOURCES})

set(CMAKE_CXX_STANDARD 17)
set_property(TARGET doctorsys PROPERTY CXX_STANDARD 17)
target_link_libraries(doctorsys ${CURSES_LIBRARIES})

# TODO: add fs on Mac/clang
# target_link_libraries(doctorsys stdc++fs)

# TODO: Run -Werror in CI.
target_compile_options(doctorsys PRIVATE -Wall -Wextra)