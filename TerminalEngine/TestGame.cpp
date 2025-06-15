
#include <iostream>
#include "Vector2D.hpp"
#include "LayerList.hpp"

#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"
#include "GameHandler.hpp"

GameLayer layer0(
    {{"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {" ", " ", " ", " ", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", " ", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", " ", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"},
     {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"}},
    false);

GameLayer layer1({{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2"},
                  {"1", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"2", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"3", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"4", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"5", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"6", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"7", " ", " ", " ", " ", " ", " ", "-", " ", " ", " ", " ", " "},
                  {"8", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                  {"9", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}},
                 true);

layerList gameLayerList = {layer0, layer1};

GameHandler gameHandler;

GameObject *objeto1 = new GameObject("objeto1", "W", true, 1, {2, 4});

GameObject *objeto2 = new GameObject("objeto2", "M", true, 1, {2, 5});

static void update()
{

    while (_kbhit())
    {
        char tecla = ' ';
        tecla = _getch();
        switch (tecla)
        {
        case 'a':
        case 'A':
            objeto1->PositionYX[1] -= 1;
            break;
        case 'd':
        case 'D':
            objeto1->PositionYX[1] += 1;
            break;
        case 'w':
        case 'W':
            objeto1->PositionYX[0] -= 1;
            break;
        case 's':
        case 'S':
            objeto1->PositionYX[0] += 1;
            break;
        default:
            std::cout << "Tecla n�o reconhecida" << std::endl;
            break;
        }
    }

    gameHandler.debugAllObjects();

    gameHandler.updater(gameLayerList);
}

int main()
{
    gameHandler.start({objeto1, objeto2});

    while (gameHandler.isRunning() == true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update();
    }
}