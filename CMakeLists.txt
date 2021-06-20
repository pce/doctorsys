cmake_minimum_required(VERSION 3.10)
project(doctorsys)
MESSAGE("Project is ${PROJECT_NAME}")

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


# add_definitions(-std=c++17)
# set( CMAKE_CXX_STANDARD 17 )
# set( CMAKE_CXX_STANDARD_REQUIRED ON )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


# TODO: Run -Werror in CI.
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

add_executable(${PROJECT_NAME}  ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

# TODO: add fs on Mac/clang
# target_link_libraries(${PROJECT_NAME} stdc++fs)

