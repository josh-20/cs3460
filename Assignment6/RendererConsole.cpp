#include "RendererConsole.hpp"

#include "rlutil.h"

#include <thread>
void RendererConsole::populate(uint8_t sizeX, uint8_t sizeY)
{

    for (int i = 0; i < sizeX; i++)
    {
        std::vector<bool> list;
        m_state.push_back(list);
        for (int j = 0; j < sizeY; j++)
        {
            m_state[i].push_back(false);
        }
    }
}

void RendererConsole::render(const LifeSimulator& simulation)
{

    if (m_state.size() == 0)
    {
        populate(simulation.getSizeX(), simulation.getSizeY());
    }
    for (int i = 0; i < simulation.getSizeX(); i++)
    {
        for (int j = 0; j < simulation.getSizeY(); j++)
        {
            if (simulation.getCell(i, j) != m_state[i][j])
            {
                rlutil::locate(j, i);
                if (simulation.getCell(i, j) == true)
                {
                    m_state[i][j] = true;
                    rlutil::setChar('x');
                }
                else
                {
                    m_state[i][j] = false;
                    rlutil::setChar(rlutil::KEY_SPACE);
                }
            }
        }
    }
}