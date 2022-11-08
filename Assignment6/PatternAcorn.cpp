#include "PatternAcorn.hpp"

#include "Pattern.hpp"

PatternAcorn::PatternAcorn()
{
    m_Pattern = {
        { false, true, false, false, false, false, false },
        { false, false, false, true, false, false, false },
        { true, true, false, false, true, true, true }
    };
}
std::uint8_t PatternAcorn::getSizeX() const
{
    return static_cast<uint8_t>(m_Pattern.size());
}
std::uint8_t PatternAcorn::getSizeY() const
{
    return static_cast<uint8_t>(m_Pattern[0].size());
}
bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    return m_Pattern[x][y];
}