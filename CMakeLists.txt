cmake_minimum_required(VERSION 3.5)
project(HackerRank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(SolveMeFirst Algorithms/Warmup/SolveMeFirst.cpp)
add_executable(CompareTheTriplets Algorithms/Warmup/CompareTheTriplets.cpp)
add_executable(AVeryBigSum Algorithms/Warmup/AVeryBigSum.cpp)
add_executable(DiagonalDifference Algorithms/Warmup/DiagonalDifference.cpp)
add_executable(PlusMinus Algorithms/Warmup/PlusMinus.cpp)
add_executable(SimpleArraySum Algorithms/Warmup/SimpleArraySum.cpp)
add_executable(Staircase Algorithms/Warmup/Staircase.cpp)
add_executable(TimeConversion Algorithms/Warmup/TimeConversion.cpp)
add_executable(CircularArrayRotation Algorithms/Warmup/CircularArrayRotation.cpp)

add_executable(ArrayLeftRotation Algorithms/CTCI/ArrayLeftRotation.cpp)
