cmake_minimum_required(VERSION 3.15)
project(TP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP main.cpp Automata.cpp
        Expression.cpp ExprMult.cpp ExprPlus.cpp Lexer.cpp States.cpp Symbol.cpp ExprVal.cpp ExprPar.cpp)