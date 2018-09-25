cmake_minimum_required(VERSION 2.8)
project(Lab01)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(main colour.cpp colour.h lsystem.cpp lsystem.h main.cpp window.cpp window.h)
target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
