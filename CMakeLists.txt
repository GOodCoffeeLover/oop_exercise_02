#CmakeFile for 2 lab

cmake_minimum_required ( VERSION 2.8)

project(oop_exercise_02)

#set(CMAKE_CXX_STANDART_11)
set(CMAKE_CXX_FLAGS "-std=gnu++11")
add_executable(oop_exercise_02 complex_trig.h complex_trig.cpp main_menu.cpp)
