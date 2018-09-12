cmake_minimum_required(VERSION 2.8)
project(Lab01)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(lab01 Lab01.cpp)
target_link_libraries(lab01 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )