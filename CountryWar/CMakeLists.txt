cmake_minimum_required(VERSION 3.24)
project(second)

set(CMAKE_CXX_STANDARD 17)

add_executable(second main.cpp entity/Character.h entity/Mole.cpp entity/Mole.h entity/Cottager.cpp entity/Cottager.h utils/Vector2D.cpp utils/Vector2D.h field/Field.cpp field/Field.h game/Game.cpp game/Game.h gui/GUI.cpp gui/GUI.h utils/Generator.cpp utils/Generator.h)
