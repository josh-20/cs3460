#include "Pattern.hpp"
#include <vector>
#include <iostream>
class PatternGosperGliderGun : public Pattern{
    public:
        std::uint8_t getSizeX();
        std::uint8_t getSizeY();
        bool getCell(std::uint8_t x, std::uint8_t y);

    private:
        std::vector<std::vector<bool>> m_Pattern;
};