cmake_minimum_required(VERSION 3.10)
project(Games)

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL_TTF REQUIRED)
include_directories(${SDL2TTF_INCLUDE_DIR})

add_executable(Games main.cpp Application.cpp Exception.cpp StateSupervisor.cpp

        collisions/SNAKEcollisionDetector.cpp

        containers/OptionContainer.cpp containers/SNAKEtextureContainer.cpp

        objects/ColorText.cpp objects/SNAKEapple.cpp objects/SNAKEmap.cpp objects/SNAKEsnake.cpp
        objects/SNAKEsnakeChunk.cpp objects/SNAKEtileMap.cpp objects/Text.cpp

        renderer/Renderer.cpp renderer/RenderAssistant.cpp

        states/MenuState.cpp states/OptionState.cpp states/SnakeState.cpp states/State.cpp

        textures/FileTexture.cpp textures/TextTexture.cpp textures/Texture.cpp

        util/Complex.cpp util/Position.cpp util/Speed.cpp util/StringCreator.cpp util/Timer.cpp)

target_link_libraries(Games ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)