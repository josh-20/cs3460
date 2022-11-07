#include "Pattern.hpp"
#include "PatternGosperGliderGun.hpp"

PatternGosperGliderGun::PatternGosperGliderGun(){
    // 38
    // 10
    m_Pattern = {
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,false,true,false,false,false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false},
        {false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,true,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false},
        {false,true,true,false,false,false,false,false,false,false,false,true,false,false,false,false,true,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false},
        {},
        {},
        {},
        {}
        };
}


std::uint8_t PatternGosperGliderGun::getSizeX(){
    return m_Pattern.size();    
}
std::uint8_t PatternGosperGliderGun::getSizeY(){
    return m_Pattern[0].size();
}
bool PatternGosperGliderGun::getCell(std::uint8_t x, std::uint8_t y){
    return m_Pattern[x][y];
}