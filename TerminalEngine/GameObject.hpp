#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <string>


#include "Vector2D.h"


class GameObject { // game object
public:


	std::string objectName = "unnamed"; // name of the object

	std::string visual = " "; //a string that defines how the object looks

	bool hasColision = false; // if it has colision

	int layerPosition = 0; //the layer where the object is located
	unsigned int PositionYX[2] = { 0,0 }; // the Y X position in the layer {Y,X}

	GameObject(std::string _objectName, std::string _visual, bool _colision, int _layerPosition, std::array<unsigned int, 2> _PositionXY) {
		objectName = _objectName;
		visual = _visual;
		hasColision = _colision;
		layerPosition = _layerPosition;

		PositionYX[0] = _PositionXY[0];
		PositionYX[1] = _PositionXY[1];
		

	}

	void debugObject() {
		std::cout << "object Debug - " << objectName << "\n";
		std::cout << "viusal:" << visual << "\n";
		std::cout << "colison:" << hasColision << "\n";
		std::cout << "layerPosition:" << layerPosition << "\n";
		std::cout << "positons: Y = " << PositionYX[0] << " | X = " << PositionYX[1] << "\n";

	}



};

class BigGameObject {

public:
	std::string objectName = "unnamed";

	std::vector<std::vector<std::string>> visual = {
		{" "," "},
		{" "," "},

	};

	bool colision = false;

	int layerPosition = 0;
	std::vector<std::array<int, 2>> positions; // primeiro é a coordenada X, depois a coordenada Y: X,Y;
	int PositionYX[2] = { 0,0 };

	BigGameObject(std::string _objectName, std::vector<std::vector<std::string>> _visual, bool _colision, int _layerPosition, std::vector<std::array<int, 2>> _positions) {
		objectName = _objectName;
		visual = _visual;
		colision = _colision;
		layerPosition = _layerPosition;
		positions = _positions;

	}


	void debugBigObject() {
		std::cout << "object Debug - " << objectName << "\n";

		std::cout << "viusal: \n";
		for (int i = 0; i < visual.size(); i++) {
			for (int ii = 0; ii < visual[0].size(); ii++) {
				std::cout << visual[i][ii];
			}
			std::cout << "\n";

		}
		std::cout << "colison:" << colision << "\n";
		std::cout << "layerPosition:" << layerPosition << "\n";
		std::cout << "positons:\n";

		for (int i = 0; i < positions.size(); i++) {
			std::cout << "cell" << i << ": ";
			std::cout << "YPos: " << positions.at(i).at(0);
			std::cout << " XPos: " << positions.at(i).at(1) << "\n";
		}
	}

};



