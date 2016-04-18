cmake_minimum_required(VERSION 2.8.4)
project(someCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")
add_definitions(-std=c++11)
set(SOURCE_FILES  employee_example/UI.cpp employee_example/Employee.cpp employee_example/Database.cpp)
add_executable(base_cpp  ${SOURCE_FILES})