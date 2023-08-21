cmake_minimum_required(VERSION 3.0.0)
project(2D_GameEngine VERSION 0.1.0)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include(CTest)
enable_testing()

add_executable(2D_GameEngine Game.cpp main.cpp TextureManager.cpp GameObject.cpp Map.cpp)
target_link_libraries(2D_GameEngine PUBLIC SDL2::SDL2 SDL2_image::SDL2_image)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)