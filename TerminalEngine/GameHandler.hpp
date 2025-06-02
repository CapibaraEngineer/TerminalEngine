#pragma once

#include <iostream>
#include <execution>
#include <thread>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <chrono>
#include <string>
#include <vector>
#include <array> 
#include <map>

#include "LayerList.hpp" // defines type "layerList", and indirectly defines gameLlayer and vector2D
#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"

class GameHandler {
public:
    GameHandler() : isGameRunning(true) {}

    // Inicia o jogo com uma lista de objetos
    void start(const std::vector<GameObject*>& GameObjects) {
        gameObjects = GameObjects;
    }

    // Atualiza o estado do jogo e renderiza as camadas
    void updater(layerList& gameLayerList) {
        if (!isGameRunning) {
            for (size_t i = 0; i < gameObjects.size(); i++) {
                delete gameObjects.at(i); // Deleta os objetos do jogo, quando o jogo não está rodando
            }
            return;
        }
        if (gameRenderer.render(gameLayerList, gameObjects) != 0) { //render error
            isGameRunning = false;
        }
    }

    // Verifica se o jogo está em execução
    bool isRunning() const {
        return isGameRunning;
    }

    // Para o jogo
    void stop() {
        isGameRunning = false;
    }

	void debugAllObjects() {
		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects.at(i)->debugObject();
		}
	}

    // Adiciona um novo objeto à lista de objetos do jogo

    void addNewGameObject(GameObject* newGameObject) {
        gameObjects.push_back(newGameObject); 
	}

    void deleteGameObject(GameObject* gameObjectToRemove) {
        auto gameObjectToRemovePosition = std::find(gameObjects.begin(), gameObjects.end(), gameObjectToRemove);
        if (gameObjectToRemovePosition != gameObjects.end()) {
            delete *gameObjectToRemovePosition; // Deleta o objeto do jogo
            gameObjects.erase(gameObjectToRemovePosition); // Remove o ponteiro da lista de objetos do jogo
		}
    }

private:

    Rendering gameRenderer; // Renderizador do jogo
    std::vector<GameObject*> gameObjects; // Lista de todos os objetos do jogo
    bool isGameRunning; // Indica se o jogo está em execução
};
