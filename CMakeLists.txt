cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)

# find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# all source files
add_executable(main
    src/main.cpp
    src/game.cpp
    src/engine.cpp
    src/entity.cpp
    src/entitymanager.cpp
    src/utility.cpp
)

target_include_directories(main PRIVATE src)

target_link_libraries(main
    SDL2::SDL2
    SDL2_image::SDL2_image
)
