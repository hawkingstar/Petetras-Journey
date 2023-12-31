cmake_minimum_required(VERSION 3.16)
project(fall2023-csc3380-project)

set(CMAKE_CXX_STANDARD 20)

add_executable(project code/armor.cpp code/cave.cpp code/character.cpp code/combat.cpp code/defense.cpp code/dungeon.cpp code/game.cpp code/item.cpp code/monster.cpp code/offense.cpp code/project.cpp)


#//paul: I commented out the code/general.hpp since according to stackoverflow it shouldn't compile with
#//the rest of hte project
# uncomment the lines below to enable the Catch2 testing infrastructure
enable_testing()
include(CTest)

target_compile_definitions(project PRIVATE CATCH_CONFIG_MAIN)
add_test(NAME project COMMAND project)
