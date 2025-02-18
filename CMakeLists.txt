cmake_minimum_required(VERSION 3.31)

project(project)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost COMPONENTS system REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

set(PROJECT_SOURCES
    src/helpers/deadline_timer.cpp
    src/helpers/deadline_timer.hpp
    src/main.cpp)

add_executable(project
    ${PROJECT_SOURCES})

target_compile_options(project PRIVATE
    -O1)

target_include_directories(project PRIVATE
    ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(project PRIVATE
    Boost::system
    fmt::fmt
    spdlog::spdlog)
