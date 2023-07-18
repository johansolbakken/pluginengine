#include <engine/engine.h>

int main() {
    Engine::Engine engine;
    engine.loadPlugin("plugins/plugin1/libplugin1.dylib");
    engine.run();
    return 0;
}