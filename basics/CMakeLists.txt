cmake_minimum_required(VERSION 3.18)
project(OpenGLBasics)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(LIBS 
    ${OPENGL_LIBRARY}
    ${GLEW_LIBRARIES}
    glfw
)

add_executable(OpenGL_Basics
    src/main.c
)

target_link_libraries(OpenGL_Basics
    ${LIBS}
)

