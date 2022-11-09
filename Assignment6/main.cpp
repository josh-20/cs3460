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
    LifeSimulator game(static_cast<uint8_t>(rlutil::trows()) + 10, static_cast<uint8_t>(rlutil::tcols() + 10));
    game.insertPattern(PatternGosperGliderGun(), 1, 1);
    RendererConsole renderer;

    rlutil::cls();
    rlutil::hidecursor();
    for (int i = 0; i < 100; i++)
    {
        renderer.render(game);
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        game.update();
    }

    return 0;
}