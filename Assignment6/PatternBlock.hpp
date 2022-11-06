#include "Pattern.hpp"
#include <iostream>

class PatternBlock : public Pattern{

    public:
        PatternBlock();
        PatternBlock(std::uint8_t startX, std::uint8_t startY);


    private:
        std::uint8_t startX;
        std::uint8_t startY;   
    
};