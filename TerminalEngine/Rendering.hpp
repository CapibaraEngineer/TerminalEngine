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

	vector2D vecRenderedFrame;
	std::string RenderedFrame = "";

	void vec2DPieceToString(std::string vecRenderedFramePiece) {

		int pieceSize = vecRenderedFramePiece.size();

		for (int i = 0; i < pieceSize; i++) {

			RenderedFrame.push_back(vecRenderedFramePiece.at(i));
		}

	}

	void frameRender(vector2D layer, bool firstInteration) {

		int numRows = layer.size();
		int numCols = layer[0].size();
		vecRenderedFrame.resize(numRows, std::vector<std::string>(numCols));

		if (firstInteration == true) {
			for (int i = 0; i < numRows; i++) {
				for (int ii = 0; ii < numCols; ii++) {
					vecRenderedFrame[i][ii] = layer[i][ii];
				}
			}
		}
		else { // not the first interantion;
			for (int i = 0; i < numRows; i++) {
				for (int ii = 0; ii < numCols; ii++) {
					if (layer[i][ii] != " ") {
						vecRenderedFrame[i][ii] = layer[i][ii];
					}

				}
			}
		}

		//vector2D to String
		//outpouting a stirng is faster than a vector 2D
		RenderedFrame = "";
		for (int i = 0; i < numRows; i++) {
			if (i != 0) {
				RenderedFrame.push_back('\n');
			}

			for (int ii = 0; ii < numCols; ii++) {
				vec2DPieceToString(vecRenderedFrame[i][ii]);
			}
		}

	}

	void outpoutFrame() {
		std::cout << RenderedFrame;
	}


public:

	void render(layerList gameLayerList) {
		auto inicio = std::chrono::high_resolution_clock::now();


		for (int i = 0; i < gameLayerList.size(); i++) {
			frameRender(gameLayerList.at(i).layer, i < 0);
		}

		
		std::cout << "\x1B[2J\x1B[H";//"limpa" o terminal, ele so desce o terminal escondendo oq esta atras na verdade. Estou usando essa aberrção pois é mais rapido que "system("cls");"


		outpoutFrame();
		auto fim = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duracao = fim - inicio;
		std::cout << "Tempo de execução: " << duracao.count() << " milissegundos" << std::endl;

	}

};