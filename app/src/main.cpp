#include <engine/engine.h>

#include <iostream>

int main()
{
    Engine::Engine engine;
    // assuming working directory is build folder
    engine.pluginManager().setPath("plugins");
    engine.run();
    return 0;
}