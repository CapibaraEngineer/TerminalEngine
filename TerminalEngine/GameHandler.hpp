#pragma once

#include <iostream>
#include <execution>
#include <thread>
#include <conio.h>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <vector>
#include <array> 
#include <map>

 
#include "Vector2D.h" //defines type "vector2D"
#include "LayerList.h" //defines type "layerList"

#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"

Rendering gameRenderer; 

std::vector<GameObject> gameObjects; //list of all game objects

bool isGameRunning = true; //if the game is running, if false, the game will stop


void start(std::vector<GameObject> GameObjects) {
	gameObjects = GameObjects;
}

void updater(layerList gameLayerList) {
	gameRenderer.render(gameLayerList, gameObjects);
}


