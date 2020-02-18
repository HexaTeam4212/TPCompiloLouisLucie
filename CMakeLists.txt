cmake_minimum_required(VERSION 3.15)
project(TP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP main.cpp automate.cpp
        E0.cpp E1.cpp E2.cpp E3.cpp E4.cpp E5.cpp E6.cpp E7.cpp E8.cpp E9.cpp
        expr.cpp exprmult.cpp exprplus.cpp lexer.cpp state.cpp symbole.cpp)