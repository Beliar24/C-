cmake_minimum_required(VERSION 3.26)
project(hillle)

set(CMAKE_CXX_STANDARD 17)

add_executable(hillle main.cpp
        game/Player.cpp
        game/Player.h
        game/HumanPlayer.cpp
        game/BotPlayer.cpp
        game/Game.cpp
)
