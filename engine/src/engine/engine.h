#pragma once

#include "pluginmanager.h"

namespace Engine
{
    class Engine
    {
    public:
        Engine(int argc, char** argv);
        void loadPlugins();
        void run();
        void close();
        PluginManager &pluginManager() { return m_pluginManager; }

    private:
        PluginManager m_pluginManager;
        bool m_running = false;
    };
}
