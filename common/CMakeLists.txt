cmake_minimum_required(VERSION 3.18)

project(OpenGLTutCommon)

add_library(common 
    ./src/loadShaders.c
)

target_include_directories(common PUBLIC
    ./include
)
