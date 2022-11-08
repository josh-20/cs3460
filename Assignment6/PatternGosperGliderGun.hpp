#pragma once
#include "Pattern.hpp"

#include <iostream>
#include <vector>
class PatternGosperGliderGun : public Pattern
{
  public:
    PatternGosperGliderGun();
    std::uint8_t getSizeX() const override;
    std::uint8_t getSizeY() const override;
    bool getCell(std::uint8_t x, std::uint8_t y) const override;

  private:
    std::vector<std::vector<bool>> m_Pattern;
};