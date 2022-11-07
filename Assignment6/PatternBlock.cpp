#include "Pattern.hpp"
#include "PatternBlock.hpp"


PatternBlock::PatternBlock(){
    m_Pattern = {
        {true,true,true,true},
        {true,false,false,true},
        {true,false,false,true},
        {true,true,true,true}
        };
}

std::uint8_t PatternBlock::getSizeX(){
    return m_Pattern.size();    
}
std::uint8_t PatternBlock::getSizeY(){
    return m_Pattern[0].size();
}
bool PatternBlock::getCell(std::uint8_t x, std::uint8_t y){
    return m_Pattern[x][y];
}