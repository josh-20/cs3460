#pragma once
#include "Renderer.hpp"

#include <vector>

class RendererConsole : public Renderer
{
  public:
    void render(const LifeSimulator& simulation) override;
    void populate(uint8_t, uint8_t);

  private:
    std::vector<std::vector<bool>> m_state;
};