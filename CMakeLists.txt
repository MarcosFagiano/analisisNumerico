cmake_minimum_required(VERSION 3.26)
project(analisisNumerico)

set(CMAKE_CXX_STANDARD 14)

add_executable(analisisNumerico
        main.cpp
        display.cpp
        raices.cpp
        ecuacionesLineales.cpp
        ajusteCurvas.cpp)
