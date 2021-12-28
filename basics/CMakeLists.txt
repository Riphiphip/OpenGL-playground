cmake_minimum_required(VERSION 3.18)
project(OpenGLBasics)

find_package(OpenGL REQUIRED)

set(LIBS 
    ${OPENGL_LIBRARY}
)

add_executable(OpenGL_Basics
    src/main.c
)

target_link_libraries(OpenGL_Basics
    ${LIBS}
)

