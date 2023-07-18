#include "engine.h"

#include <iostream>
namespace Engine
{
    Engine::Engine(int argc, char **argv)
    {
        auto pluginsFolder = std::filesystem::weakly_canonical(std::filesystem::path(argv[0])).parent_path().parent_path() / "plugins";
        m_pluginManager.setPath(pluginsFolder);
    }

    void Engine::loadPlugins()
    {
        std::vector<std::string> neededPlugins = {"plugin1"};
        m_pluginManager.loadPlugins(neededPlugins);
    }

    void Engine::run()
    {
        loadPlugins();
        std::cout << "Engine is running" << std::endl;
    }
}
