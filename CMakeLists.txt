cmake_minimum_required(VERSION 3.28.0)
project(warhammer-rpg)
include_directories(include)
add_executable(warhammer 
       src/main.cpp
       src/player/player.cpp
       src/utility/faith.cpp
       src/utility/hp.cpp
       src/utility/levelling.cpp)
