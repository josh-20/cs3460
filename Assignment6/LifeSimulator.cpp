#include "LifeSimulator.hpp"
#include "Pattern.hpp"
#include <iostream>
#include <vector>

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    std::vector<std::vector<bool>> m_board;
    for (int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            m_board[i][j] = false;
        }
    }
}

void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY){
    
}

void update(){
    
}

bool getCell(std::uint8_t x, std::uint8_t y){
}


