#include "LifeSimulator.hpp"
#include "Pattern.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "Renderer.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

int main()
{
    LifeSimulator game(rlutil::trows(), rlutil::tcols());
    game.insertPattern(PatternBlock(), 5, 5);
    game.insertPattern(PatternGlider(), 20, 20);
    RendererConsole renderer;

    rlutil::cls();
    for (int i = 0; i < 20; i++)
    {
        renderer.render(game);
        game.update();
    }

    return 0;
}