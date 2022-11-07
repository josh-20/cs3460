#include "LifeSimulator.hpp"
#include "Pattern.hpp"
#include <iostream>
#include <vector>

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    for (int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX; j++){
            m_board[j].push_back(false);
        }
    }
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY){
    
}

void LifeSimulator::update(){
    std::vector<std::vector<bool>>& newBoard = m_board;
    // Update new board
    // using the four rules
    std::swap(m_board, newBoard);    
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const{
    return m_board[x][y];
}


