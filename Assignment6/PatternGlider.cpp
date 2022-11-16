#include "PatternGlider.hpp"

#include "Pattern.hpp"
PatternGlider::PatternGlider()
{
    m_Pattern = {
        { true, false, false },
        { false, true, true },
        { true, true, false }
    };
}

std::uint8_t PatternGlider::getSizeX() const
{
    return static_cast<uint8_t>(m_Pattern.size());
}
std::uint8_t PatternGlider::getSizeY() const
{
    return static_cast<uint8_t>(m_Pattern[0].size());
}
bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    return m_Pattern[x][y];
}
