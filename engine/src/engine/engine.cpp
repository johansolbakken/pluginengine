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
#ifdef __linux__
        neededPlugins.push_back("linuxplugin");
#endif
#ifdef __APPLE__
        neededPlugins.push_back("macplugin");
#endif
        m_pluginManager.loadPlugins(neededPlugins);
    }

    void Engine::run()
    {
        loadPlugins();
        std::cout << "Engine is running" << std::endl;

        m_running = true;

        for (auto& [_, plugin] : m_pluginManager.plugins()) {
            plugin->setEventCallback([this]() {
                close();
            });
            plugin->init();
        }

        while (m_running) {
            for (auto& [_, plugin] : m_pluginManager.plugins()) {
                plugin->update();
            }
        }

        for (auto& [_, plugin] : m_pluginManager.plugins()) {
            plugin->shutdown();
        }
    }

    void Engine::close() {
        m_running = false;
    }
}
