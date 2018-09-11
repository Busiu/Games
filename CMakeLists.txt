cmake_minimum_required(VERSION 3.10)
project(Games)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL_TTF REQUIRED)
include_directories(${SDL2TTF_INCLUDE_DIR})

add_executable(Games main.cpp Application.cpp Exception.cpp Window.cpp
        states/State.cpp states/MenuState.cpp states/OptionState.cpp textures/Texture.cpp textures/TextTexture.cpp)

target_link_libraries(Games ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)