#include "Pattern.hpp"
#include "PatternGlider.hpp"
PatternGlider::PatternGlider(){
    m_Pattern = {
        {false,false,true},
        {true,false,true},
        {false,true,true}
        };
}

std::uint8_t PatternGlider::getSizeX(){
    return m_Pattern.size();    
}
std::uint8_t PatternGlider::getSizeY(){
    return m_Pattern[0].size();
}
bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y){
    return m_Pattern[x][y];
}
