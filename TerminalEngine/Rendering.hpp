#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <array> 
#include <map>

#include "GameLayer.hpp"
#include "Vector2D.h"
#include "LayerList.h"

class Rendering {
protected:

	layerList gameLayerListCopy;
	vector2D vecRenderedFrame;
	std::string renderedFrame = "";

	void clearScreen() {
		std::cout << "\x1B[2J\x1B[H"; // "limpa" o terminal, ele apenas desce o terminal escondendo o que esta atras na verdade. Estou usando essa aberrção porque em testes ele foi mais rapido que o system("cls")
	}

	void objectRender(layerList& gameLayerList, std::vector<GameObject*> gameObjects) {
		
		for (int i = 0; i < gameObjects.size(); i++) {
			GameObject* objToBeRendered = gameObjects.at(i);
			gameLayerList[objToBeRendered->layerPosition].layer[objToBeRendered->PositionYX[0]][objToBeRendered->PositionYX[1]] = objToBeRendered->visual;
		}
	}

	void vecToString(int numRows, int numCols) {
		renderedFrame = "";
		for (int i = 0; i < numRows; i++) {

			if (i != 0) {
				renderedFrame.push_back('\n');
			}

			for (int ii = 0; ii < numCols; ii++) {
				renderedFrame.append(vecRenderedFrame[i][ii]);
			}
		}
	}

	void layerRender(const layerList& gameLayerList, unsigned __int8 layerIndex) {

		vector2D currentLayer = gameLayerList[layerIndex].layer;

		int numRows = currentLayer.size();
		int numCols = currentLayer[0].size();

		if (layerIndex == 0) {
			vecRenderedFrame.resize(numRows, std::vector<std::string>(numCols));
			for (int i = 0; i < numRows; ++i) {
				std::copy(currentLayer[i].begin(), currentLayer[i].end(), vecRenderedFrame[i].begin());
			}
		}
		else { // not the first interantion;
			for (int i = 0; i < numRows; i++) {
				for (int ii = 0; ii < numCols; ii++) {
					if (currentLayer[i][ii] != " ") {
						vecRenderedFrame[i][ii] = currentLayer[i][ii];
					}

				}
			}
		}

		if (layerIndex == gameLayerList.size() - 1) {
			vecToString(numRows, numCols);
		}
		else {
			layerRender(gameLayerList, layerIndex + 1);
		}
		

	}


public:

	void render(layerList& gameLayerList, const std::vector<GameObject*>& gameObjects) {
		
		if (gameLayerList.size() == 0) {
			std::cout << "\033[31m provided gameLayerList has no layers to render\033[0m";
			
		}
		gameLayerListCopy = gameLayerList;

		objectRender(gameLayerListCopy, gameObjects);

		layerRender(gameLayerListCopy, 0);
		
		clearScreen();

		std::cout << renderedFrame;
	}

};
