cmake_minimum_required(VERSION 3.23)
project(cosmonaut)

set(CMAKE_CXX_STANDARD 23)

add_executable(cosmonaut main.cpp PysicsObj.cpp PhysicsObj.h geometry/Vect2D.h)

find_package(SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})