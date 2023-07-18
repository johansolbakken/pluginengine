#include <engine/engine.h>

#include <iostream>

int main(int argc, char **argv)
{
    // must give path to plugins
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <path to plugins>" << std::endl;
        return 1;
    }

    Engine::Engine engine;
    engine.pluginManager().setPath(argv[1]);
    // engine.pluginManager().loadPlugin("plugins/plugin1/libplugin1.dylib");
    // engine.pluginManager().loadAllPlugins();
    engine.pluginManager().loadPlugins({"plugin1", "plugin2"});
    engine.run();
    return 0;
}