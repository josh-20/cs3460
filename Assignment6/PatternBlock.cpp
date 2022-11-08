#include "PatternBlock.hpp"

PatternBlock::PatternBlock()
{
    m_Pattern = {
        { true, true, true, true },
        { true, false, false, true },
        { true, false, false, true },
        { true, true, true, true }
    };
}

std::uint8_t PatternBlock::getSizeX() const
{
    return static_cast<uint8_t>(m_Pattern.size());
}
std::uint8_t PatternBlock::getSizeY() const
{
    return static_cast<uint8_t>(m_Pattern[0].size());
}
bool PatternBlock::getCell(std::uint8_t x, std::uint8_t y) const
{
    return m_Pattern[x][y];
}