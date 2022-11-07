#include "Pattern.hpp"
#include <iostream>
#include <vector>
class PatternBlock : public Pattern{
    public:
        std::uint8_t getSizeX();
        std::uint8_t getSizeY();
        bool getCell(std::uint8_t x, std::uint8_t y);

    private:
        std::vector<std::vector<bool>> m_Pattern;
};