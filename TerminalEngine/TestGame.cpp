
#include <iostream>
#include "Vector2D.h"
#include "LayerList.h"

#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"
#include "GameHandler.hpp"

GameLayer layer0(
    {
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"}},
    false
    );

GameLayer layer1({
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," ","-"," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "," "," "," "," "," "," "} },
    true
    );


layerList gameLayerList = { layer0, layer1 };

Rendering gameRenderer;

GameObject objeto("objeto", "W", true, 1, {2,3});


void update() {

    while (_kbhit()) {
        char tecla = ' ';
        tecla = _getch();
        switch (tecla) {
        case 'a':
        case 'A':
            //objeto.PositionYX[1] -= 1;
            break;
        default:
            break;
        }
    }


    updater(gameLayerList);
    gameRenderer.render(gameLayerList);
    
    objeto.debugObject();

   
}

int main()
{
    start({ objeto });

    gameRenderer.render(gameLayerList);

    
    while (gameRunning == true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update();
    }
    

}