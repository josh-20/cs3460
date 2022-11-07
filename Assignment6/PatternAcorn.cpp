#include "Pattern.hpp"
#include "PatternAcorn.hpp"

PatternAcorn::PatternAcorn(){
    m_Pattern = {
        {false,true,false,false,false,false,false},
        {false,false,false,true,false,false,false},
        {true,true,false,false,true,true,true}
        };

}
std::uint8_t PatternAcorn::getSizeX(){
    return m_Pattern.size();    
}
std::uint8_t PatternAcorn::getSizeY(){
    return m_Pattern[0].size();
}
bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y){
    return m_Pattern[x][y];
}