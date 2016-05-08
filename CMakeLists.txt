cmake_minimum_required(VERSION 2.8.4)
project(someCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")
add_definitions(-std=c++11)
#set(SOURCE_FILES  sp_polymorh/SpreadSheetCell.cpp sp_polymorh/StringSpreadSheetCell.cpp sp_polymorh/DoubleSpreadSheetCell.cpp sp_polymorh/DoubleSpreadSheetCell.h sp_polymorh/spp_main.cpp)
#set(SOURCE_FILES base/inheritance2.cpp)
#set(SOURCE_FILES spreadsheet/sp_main.cpp spreadsheet/SpreadSheetCell.cpp spreadsheet/SpreadSheetImpl.cpp
#spreadsheet/SpreadSheet.cpp)
#set(SOURCE_FILES base/mult_inheritance.cpp )
#set(SOURCE_FILES base/milEstimator.cpp)
set(SOURCE_FILES  base/base2.cpp  base/FileError.h base/FileOpenError.cpp base/FileOpenError.cpp base/FileOpenError.h base/FileReadError.cpp base/FileReadError.h )
add_executable(base_cpp  ${SOURCE_FILES})