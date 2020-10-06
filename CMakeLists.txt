cmake_minimum_required(VERSION 3.10)
project(doctorsys)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

IF(UNIX)
  IF(APPLE)
    SET(SYS "DARWIN")
  ELSE(APPLE)
    SET(SYS "LINUX")
  ENDIF(APPLE)
ELSE(UNIX)
  IF(WIN32)
    SET(SYS "Win32")
  ELSE(WIN32)
    SET(SYS "Unknown")
  ENDIF(WIN32)
ENDIF(UNIX)
MESSAGE("System is ${SYS}")

include_directories(include)
# file(GLOB SOURCES "src/*.cpp")
SET(SOURCES src/file_util.cpp src/format.cpp src/main.cpp src/screen.cpp src/system.cpp)

IF(UNIX)
  IF(APPLE)
    SET(SOURCES ${SOURCES} src/system_darwin.cpp)
  ELSE(APPLE)
    SET(SOURCES ${SOURCES} src/system_linux.cpp)
  ENDIF(APPLE)
ELSE(UNIX)
  IF(WIN32)
    SET(SOURCES ${SOURCES} src/system_win.cpp)
  ENDIF(WIN32)
ENDIF(UNIX)


add_executable(doctorsys ${SOURCES})

set(CMAKE_CXX_STANDARD 17)
set_property(TARGET doctorsys PROPERTY CXX_STANDARD 17)
target_link_libraries(doctorsys ${CURSES_LIBRARIES})

# TODO: add fs on Mac/clang
# target_link_libraries(doctorsys stdc++fs)

# TODO: Run -Werror in CI.
target_compile_options(doctorsys PRIVATE -Wall -Wextra)