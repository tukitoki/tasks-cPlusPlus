cmake_minimum_required(VERSION 3.24)
project(second)

set(CMAKE_CXX_STANDARD 17)

add_executable(second main.cpp entity/Character.h entity/Mole.cpp entity/Mole.h entity/Cottager.cpp entity/Cottager.h utils/Vector2D.cpp utils/Vector2D.h Field.cpp Field.h Game.cpp Game.h GUI.cpp GUI.h utils/Generator.cpp utils/Generator.h)
