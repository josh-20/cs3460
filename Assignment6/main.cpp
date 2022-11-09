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

#include <thread>
int main()
{
    LifeSimulator game(rlutil::trows() + 10, rlutil::tcols() + 10);
    game.insertPattern(PatternGosperGliderGun(), 1, 1);
    RendererConsole renderer;

    rlutil::cls();
    rlutil::hidecursor();
    for (int i = 0; i < 20; i++)
    {
        renderer.render(game);
        std::cout << std::flush;
        game.update();
    }

    return 0;
}