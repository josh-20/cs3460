#include "PatternBlinker.hpp"

#include "Pattern.hpp"

#include <vector>

PatternBlinker::PatternBlinker()
{
    m_Pattern = {
        { false, false, false },
        { true, true, true },
        { false, false, false },
    };
}

std::uint8_t PatternBlinker::getSizeX() const
{
    return static_cast<uint8_t>(m_Pattern.size());
}
std::uint8_t PatternBlinker::getSizeY() const
{
    return static_cast<uint8_t>(m_Pattern[0].size());
}
bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const
{
    return m_Pattern[x][y];
}