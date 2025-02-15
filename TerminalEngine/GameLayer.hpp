#pragma once

#include <vector>
#include <iostream>

#include "Vector2D.h"

class GameLayer {
public:
	vector2D layer; //the actual layer, a Bidimesional vector


	bool hasColision = false; //colision is enabled or disabled for the objects in this layer

	GameLayer(vector2D _layer, bool _hasColision) {
		layer = _layer;
		hasColision = _hasColision;
	}
};