#include "LifeSimulator.hpp"

#include "Pattern.hpp"

#include <iostream>
#include <vector>

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    for (int i = 0; i < sizeY; i++)
    {
        std::vector<bool> list;
        m_board.push_back(list);
        for (int j = 0; j < sizeX; j++)
        {
            m_board[i].push_back(false);
        }
    }
}
void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    if (pattern.getSizeY() < (getSizeY() - startY))
    {

        for (uint8_t i = 0; i < pattern.getSizeX(); i++)
        {
            for (uint8_t j = 0; j < pattern.getSizeY(); j++)
            {
                if (startX + i >= m_board.size() || startX + i < 0)
                {
                    continue;
                }
                else if (startY + j >= m_board.size() || startY + j < 0)
                {
                    continue;
                }
                else if (pattern.getCell(i, j) == true)
                {
                    m_board[startX + i][startY + j] = true;
                }
            }
        }
    }
}

void LifeSimulator::update()
{

    // get number of neighbors

    // iterate over m_board and check each cell's neighbors and check for alive cells
    // based on
    // Update new board
    // using the four rules

    std::vector<std::vector<bool>> newBoard;
    for (int i = 0; i < static_cast<int>(m_board.size()); i++)
    {
        std::vector<bool> list;
        newBoard.push_back(list);
        for (int j = 0; j < static_cast<int>(m_board[0].size()); j++)
        {
            newBoard[i].push_back(false);
        }
    }
    // create the updated board
    for (uint8_t i = 0; i < getSizeX(); i++)
    {
        for (uint8_t j = 0; j < getSizeY(); j++)
        {
            uint8_t aliveNeighbors = 0;
            // count number of alive neighbors
            for (int l = -1; l <= 1; l++)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (l == 0 && k == 0)
                    {
                        continue;
                    }
                    else
                    {
                        if (i + l >= getSizeX() || i + l < 0)
                        {
                            continue;
                        }
                        else if (j + k >= getSizeY() || j + k < 0)
                        {
                            continue;
                        }
                        else if (m_board[i + l][j + k] == true)
                        {
                            aliveNeighbors += 1;
                        }
                    }
                }
                // rule check
            }
            if (aliveNeighbors <= 1)
            {
                newBoard[i][j] = false;
            }
            else if (aliveNeighbors > 3)
            {
                newBoard[i][j] = false;
            }
            else if (aliveNeighbors == 3)
            {
                newBoard[i][j] = true;
            }
            else
            {
                newBoard[i][j] = getCell(i, j);
            }
        }
    }
    std::swap(m_board, newBoard);
}
bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    return m_board[x][y];
}
std::uint8_t LifeSimulator::getSizeX() const
{
    return static_cast<uint8_t>(m_board.size());
}
std::uint8_t LifeSimulator::getSizeY() const
{
    return static_cast<uint8_t>(m_board[0].size());
}
