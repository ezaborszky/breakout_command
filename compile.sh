#!/bin/bash
g++ ./src/main.cpp ./src/game.cpp ./src/engine.cpp ./src/entitymanager.cpp ./src/entity.cpp ./src/utility.cpp -lSDL2 -lSDL2_image -o ./build/main
echo "Build complete!"
