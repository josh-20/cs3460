#include "Pattern.hpp"
#include "PatternBlinker.hpp"
#include <vector>

PatternBlinker::PatternBlinker(){
    m_Pattern = {
        {false,false,false},
        {true,true,true},
        {false,false,false},
    };
}

std::uint8_t PatternBlinker::getSizeX(){
    return m_Pattern.size();    
}
std::uint8_t PatternBlinker::getSizeY(){
    return m_Pattern[0].size();
}
bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y){
    return m_Pattern[x][y];
}