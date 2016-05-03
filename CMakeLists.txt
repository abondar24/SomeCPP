cmake_minimum_required(VERSION 2.8.4)
project(someCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")
add_definitions(-std=c++11)
set(SOURCE_FILES spreadsheet/sp_main.cpp spreadsheet/SpreadSheetCell.cpp spreadsheet/SpreadSheetImpl.cpp
        spreadsheet/SpreadSheet.cpp)
add_executable(base_cpp  ${SOURCE_FILES})