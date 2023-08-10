#include <engine/engine.h>

int main(int argc, char** argv)
{
    Engine::Engine engine(argc, argv);
    engine.pluginManager().loadPlugin("../plugins/zigplug/zig-out/lib/libzigplug.dylib");
    engine.run();
    return 0;
}
