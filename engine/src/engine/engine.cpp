#include "engine.h"

#include <iostream>
namespace Engine
{
    void Engine::run()
    {
        std::cout << "Running engine" << std::endl;

        std::cout << "Loaded plugins: " << std::endl;
        for (auto &plugin : m_pluginManager.plugins())
        {
            std::cout << "\tRunning plugin: " << plugin->getPluginName() << std::endl;
        }
    }
}