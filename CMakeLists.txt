cmake_minimum_required(VERSION 3.2)

project(engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/local/include")
link_directories("/usr/local/lib")

set(SOURCE_FILES main.cpp Engine/RenderManager.h Engine/Engine.h Engine/Managers.h Engine/CoreManager.h Engine/Manager.h Engine/Initializable.h Engine/Destroyable.h Engine/Err.h Engine/vec2.h Engine/Texture.h Engine/Renderable.h Engine/EventManager.h Engine/LoopManager.h Engine/Command.h Engine/util.h Engine/RealTimeManager.h Engine/Updatable.h Engine/Level.h Engine/GameState.h states/LevelGameState/WorldGameState.h Engine/AssetManager.h Engine/Positionable.h Engine/Dimensionable.h Engine/Positionable.h Engine/Dimensionable.h Engine/Rotatable.h Engine/Flippable.h Engine/Croppable.h Engine/World.h Engine/InputComponent.h Engine/PhysicsComponent.h Engine/RenderComponent.h Engine/GameObject.h states/LevelGameState/BoxGameObject.h Engine/PhysicalObject.h Engine/GameControllerManager.h)
add_executable(engine ${SOURCE_FILES})

target_link_libraries(engine SDL2)
target_link_libraries(engine SDL2_image)
target_link_libraries(engine SDL2_ttf)

target_compile_features(engine PRIVATE cxx_range_for)