cmake_minimum_required(VERSION 3.18)
project(OpenGLBasics)

set(CMAKE_BUILD_TYPE Debug)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)


add_subdirectory(../common libs/common/build)

set(LIBS 
    ${OPENGL_LIBRARY}
    ${GLEW_LIBRARIES}
    glfw
    common
)

add_executable(OpenGL_Basics
    src/main.c
)

target_link_libraries(OpenGL_Basics
    ${LIBS}
)



