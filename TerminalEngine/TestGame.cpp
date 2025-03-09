
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
    {" "," "," "," ","_","_","_","_","_","_","_","_","_"},
    {"_","_","_"," ","_","_","_","_","_","_","_","_","_"},
    {"_","_","_"," ","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"}},
    false
    );

GameLayer layer1({
    {"0","1","2","3","4","5","6","7","8","9","0","1","2"},
    {"1"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"2"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"3"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"4"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"5"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"6"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"7"," "," "," "," "," "," ","-"," "," "," "," "," "},
    {"8"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"9"," "," "," "," "," "," "," "," "," "," "," "," "} },
    true
    );


layerList gameLayerList = { layer0, layer1 };

GameHandler gameHandler;

GameObject objeto1("objeto", "W", true, 1, {1,4});

GameObject objeto2("objeto", "M", true, 1, {2,5});



void update() {

    //while (_kbhit()) {
    //    char tecla = ' ';
    //    tecla = _getch();
    //    switch (tecla) {
    //    case 'a':
    //    case 'A':
    //        //objeto.PositionYX[1] -= 1;
    //        break;
    //    default:
    //        break;
    //    }
    //}

    layer1.layer[2][3] = objeto1.visual;

    objeto1.debugObject();
    



    gameHandler.updater(gameLayerList);
}

int main()
{
    gameHandler.start({ objeto1, objeto2 });
    
    
    while (gameHandler.isRunning() == true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update();
    }
    

}