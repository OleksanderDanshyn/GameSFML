cmake_minimum_required(VERSION 3.27)
project(gameProject)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(gameProject main.cpp
        Player.h
        Walls.cpp
        Walls.h
        Player.cpp
        Weapon.cpp
        Weapon.h
        Enemy.cpp
        Enemy.h
)

target_link_libraries(gameProject sfml-graphics)
