#include "RendererConsole.hpp"

#include "rlutil.h"
void RendererConsole::render(const LifeSimulator& simulation)
{
    for (int i = 0; i < simulation.getSizeX(); i++)
        for (int j = 0; j < simulation.getSizeY(); j++)
        {
            if (simulation.getCell(i, j) == false)
            {
                rlutil::locate(i, j);
                rlutil::setChar(rlutil::KEY_SPACE);
            }
            else
            {
                rlutil::locate(i, j);
                rlutil::setChar('x');
            }
        }
}