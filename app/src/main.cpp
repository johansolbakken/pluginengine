#include <engine/engine.h>

#include <iostream>
#include <functional>

int main(int argc, char** argv)
{
    Engine::Engine engine(argc, argv);
    engine.run();
    return 0;
}
