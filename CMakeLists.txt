cmake_minimum_required(VERSION 3.5)

project(batools)

set(CMAKE_CXX_COMPILER /opt/homebrew/Cellar/llvm/17.0.6_1/bin/clang++)
set(CMAKE_CXX_STANDARD 23)

include_directories(include src)
link_directories(include src)
add_library(batools src/version.cpp
        src/batools_exception.cpp
        src/numerical_dataset.cpp
        src/example_mean_convergence.cpp)
add_executable(playground playground.cpp)
target_link_libraries(playground PUBLIC batools)