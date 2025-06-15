#pragma once

#include <iostream>
#include <vector>
#include <array>

#include "GameLayer.hpp"
#include "Vector2D.hpp"
#include "LayerList.hpp"

class Rendering
{
protected:
	layerList gameLayerListCopy;
	vector2D vecRenderedFrame;
	std::string renderedFrame = "";

	void clearScreen()
	{
		std::cout << "\x1B[2J\x1B[H"; // "limpa" o terminal, ele apenas desce o terminal escondendo o que esta atras na verdade. Estou usando essa aberr��o porque em testes ele foi mais rapido que o system("cls")
	}

	void objectRender(layerList &gameLayerList, std::vector<GameObject *> gameObjects)
	{

		for (int i = 0; i < gameObjects.size(); i++)
		{
			GameObject *objToBeRendered = gameObjects.at(i);
			gameLayerList[objToBeRendered->layerPosition].layer[objToBeRendered->PositionYX[0]][objToBeRendered->PositionYX[1]] = objToBeRendered->visual;
		}
	}

	void vecToString(size_t numRows, size_t numCols)
	{
		renderedFrame = "";
		for (size_t i = 0; i < numRows; i++)
		{

			if (i != 0)
			{
				renderedFrame.push_back('\n');
			}

			for (size_t ii = 0; ii < numCols; ii++)
			{
				renderedFrame.append(vecRenderedFrame[i][ii]);
			}
		}
	}

	void layerRender(const layerList &gameLayerList, unsigned __int8 layerIndex)
	{

		vector2D currentLayer = gameLayerList[layerIndex].layer;

		size_t numRows = currentLayer.size();
		size_t numCols = currentLayer[0].size();

		if (layerIndex == 0)
		{
			vecRenderedFrame.resize(numRows, std::vector<std::string>(numCols));
			for (size_t i = 0; i < numRows; ++i)
			{
				std::copy(currentLayer[i].begin(), currentLayer[i].end(), vecRenderedFrame[i].begin());
			}
		}
		else
		{ // not the first interantion;
			for (size_t i = 0; i < numRows; i++)
			{
				for (size_t ii = 0; ii < numCols; ii++)
				{
					if (currentLayer[i][ii] != " ")
					{
						vecRenderedFrame[i][ii] = currentLayer[i][ii];
					}
				}
			}
		}

		if (layerIndex == gameLayerList.size() - 1)
		{
			vecToString(numRows, numCols);
		}
		else
		{
			layerRender(gameLayerList, layerIndex + 1);
		}
	}

public:
	int render(layerList &gameLayerList, const std::vector<GameObject *> &gameObjects)
	{

		if (gameLayerList.size() == 0)
		{
			std::cerr << "\033[31m Render error: Provided gameLayerList has no layers to render\n the program will now exit\033[0m";
			return 1;
		}
		gameLayerListCopy = gameLayerList;

		objectRender(gameLayerListCopy, gameObjects);

		layerRender(gameLayerListCopy, 0);

		clearScreen();

		std::cout << renderedFrame;

		return 0;
	}
};