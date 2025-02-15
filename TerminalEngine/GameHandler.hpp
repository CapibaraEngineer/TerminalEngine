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

#include "Vector2D.h"
#include "LayerList.h" //defines type "layerList"

#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"

std::vector<GameObject> gameObjectWithColission;

bool gameRunning = true; //if the game is running, if false, the game will stop


void start(std::vector<GameObject> GameObjects) {


	for (int i = 0; i < GameObjects.size(); i++) {
		if (GameObjects.at(i).hasColision == true) {
			gameObjectWithColission.push_back(GameObjects.at(i));
		}
	}
}

void updater(layerList gameLayerList) {

	for (int i = 0; i < gameObjectWithColission.size(); i++) {
		GameObject GameObjectBeingUpdated = gameObjectWithColission.at(i);
		gameLayerList.at(GameObjectBeingUpdated.layerPosition).layer[GameObjectBeingUpdated.PositionYX[0]][GameObjectBeingUpdated.PositionYX[1]] = GameObjectBeingUpdated.visual;
	}
	
	//debug
	for (int i = 0; i < gameObjectWithColission.size(); i++) {
		std::cout << gameObjectWithColission.at(i).objectName;
	}
}

