cmake_minimum_required(VERSION 2.8)
project(Lab02)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(lab02 main.cpp)
target_link_libraries(lab02 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
