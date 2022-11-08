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
    std::vector<std::vector<bool>> newBoard;
    for (int i = 0; i < m_board.size(); i++){
        for(int j = 0; j < m_board[0].size(); j++){
            newBoard[j].push_back(false);
        }
    }
    //create the updated board
    for(int i = 0; i < m_board.size(); i++){
        for(int j = 0; j < m_board[0].size(); j++){
            uint8_t aliveNeighbors = 0;
            // count number of alive neighbors
            for (int l = -1; l <= 1; l++){
                for(int k = -1; k <= 1; k++){
                    if(l != 0 && j != 0){
                        if (m_board[i + l][j + k] == true){
                            aliveNeighbors += 1;
                        }
                    }
                }
            }
            //rule check
            if(aliveNeighbors >= 2 && aliveNeighbors <= 3){
                newBoard[i][j] = true;
            }else if(aliveNeighbors > 3){
                newBoard[i][j] = false;
            }else{
                newBoard[i][j] = false;
            }
        }
    }
    // get number of neighbors 

    // iterate over m_board and check each cell's neighbors and check for alive cells
    // based on  
    // Update new board
    // using the four rules
    std::swap(m_board, newBoard);    
}
bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const{
    return m_board[x][y];
}


