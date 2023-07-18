#include "engine.h"

#include <iostream>
namespace Engine
{
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