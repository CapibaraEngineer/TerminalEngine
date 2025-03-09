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

#include "Vector2D.h" // defines type "vector2D"
#include "LayerList.h" // defines type "layerList"
#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"

class GameHandler {
public:
    GameHandler() : isGameRunning(true) {}

    // Inicia o jogo com uma lista de objetos
    void start(const std::vector<GameObject>& GameObjects) {
        gameObjects = GameObjects;
    }

    // Atualiza o estado do jogo e renderiza as camadas
    void updater(const layerList& gameLayerList) {
        gameRenderer.render(gameLayerList, gameObjects);
    }

    // Verifica se o jogo está em execução
    bool isRunning() const {
        return isGameRunning;
    }

    // Para o jogo
    void stop() {
        isGameRunning = false;
    }

private:
    Rendering gameRenderer; // Renderizador do jogo
    std::vector<GameObject> gameObjects; // Lista de todos os objetos do jogo
    bool isGameRunning; // Indica se o jogo está em execução
};
