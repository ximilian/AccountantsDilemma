cmake_minimum_required(VERSION 2.8)
project (AccDilemma) 

FIND_PACKAGE(Boost 1.53 COMPONENTS program_options REQUIRED)

include_directories(.)
add_executable (acc_dilemma main.cpp SubsetSumSolver.cpp) 
target_link_libraries(acc_dilemma ${Boost_PROGRAM_OPTIONS_LIBRARY})

